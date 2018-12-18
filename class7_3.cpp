#include <iostream>
#include <vector>
using namespace std;

class Screen
{
  public:
    typedef string::size_type pos;
    //using pos = string::size_type;
    friend class Window_mgr; //定义友元类
    friend void Window_mgr::clear(ScreenIndex);
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; } //  隐式内联
    char get(pos, pos) const;                     //显式内联
    Screen &move(pos, pos);                       //可以晚点内联
    Screen &set(char);
    Screen &set(pos, pos, char);
    void some_member() const;
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    }

  private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    mutable size_t access_ctr; //即使在一个const对象内也可以更改
    void do_display(ostream &os) const { os << contents; }
};

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this; //作为左值返回
}

inline Screen &Screen::set(pos r, pos col, char c)
{
    contents[r * width + col] = c;
    return *this;
}

void Screen::some_member() const
{
    ++access_ctr; //任何函数都可对他更改
}

class Window_mgr
{
  public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);

  private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');   //友元类可以访问private成员
}

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << endl;
}