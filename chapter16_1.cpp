#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <string>
using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
    if(v1 < v2)
        return -1;
    if(v1 > v2)
        return 1;
    return 0;
}

template <typename I, typename T>
I find(I b, I e, const T &v)
{
    while(b != e && *b != v)
        b++;
    return b;
}

template <typename T, size_t N>
const T* my_begin(const T (&a)[N])
{
    return &a[0];
}

template <typename T, size_t N>
const T* my_end(const T (&a)[N])
{
    return &a[0] + N;
}

template <typename T, size_t N>
void print(const T (&a)[N])
{
    for (auto i = my_begin(a); i != my_end(a); i ++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

template <typename T> class Blob{
    public:
      typedef T value_type;
      typedef typename vector<T>::size_type size_type;

      //construtors
      Blob();
      Blob(initializer_list<T> il);
      size_type size() const { return data->size(); }
      bool empty() const { return data->empty(); }
      void push_back(const T &t) { data->push_back(t); }
      //move version
      void push_back(T &&t) { data->push_back(move(t)); }
      void pop_back();

      //element access
      T &back();
      T &operator[](size_type i);

    private:
      shared_ptr<vector<T>> data;
      void check(size_type i, const string &msg) const;
};

template <int H, int W>
class Screen{
    public:
      Screen() : contents(H * W, ' '){}
      Screen(char c) : contents(H * W, c){}
      friend class Window_mgr;
      char get() const { return contents[cursor]; }
      inline char get(int, int) const;
      Screen &clear(char = bkground);

      Screen &move(int r, int c);
      Screen &set(char);
      Screen &set(int, int, char);
      Screen &display(ostream &os) { do_display(os);
          return *this;
      }
      const Screen &display(ostream &os) const { do_display(os);
          return *this;
      }

    private:
      void do_display(ostream &os) const{
          os << contents;
      }
      static const char bkground = ' ';
      int cursor = 0;
      string contents;
};

template <int H, int W>
Screen<H,W> &Screen<H, W>::clear(char c)
{
    contents = string(H * W, c);
    return *this;
}

template<int H, int W>
inline Screen<H, W> &Screen<H, W>::move(int r, int c)
{
    int row = r * W;        //计算行位置
    cursor = row + c;       //将光标移动到此行指定列
    return *this;           //返回当前对象
}

template<int H, int W>
char Screen<H, W>::get(int r, int c) const
{
    int row = r * W;        //计算行位置
    return contents[row + c];   //将光标移动到此指定列
}

template<int H, int W>
inline Screen<H, W> &Screen<H, W>::set(char c)
{
    contents[cursor] = c;
    return *this;
}

template <int H, int W>
inline Screen<H, W> &Screen<H, W>::set(int r, int col, char ch)
{
    contents[r * W + col] = ch;
    return *this;
}

void ques16_14()
{
    Screen<5, 3> myScreen;
    //myScreen.display(cout);
    myScreen.move(4, 0).set('#');
    myScreen.display(cout);
    cout << endl;

    Screen<5, 5> nextScreen('X');
    nextScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    nextScreen.display(cout);
    cout << endl;
}

void ques16_4()
{
    vector<int> vi = {1,2,3,4,5,6,7,8};
    list<string> ls = {"hello","world","!"};

    auto iter = find(vi.begin(), vi.end(), 1);
    if(iter == vi.end())
        cout << "not found" << endl;
    else
        cout << "find 2 in position " << iter - vi.begin() + 1 << endl;

    auto iter1 = find(ls.begin(), ls.end(), "!");
    if(iter1 == ls.end())
        cout << "not found" << endl;
    else
        cout << "find !" << endl;
}

void ques16_5()
{
    int a[6] = {1,2,3,4,5,6};
    string s[4] = {"hello","world","!","!"};

    print(a);
    print(s);
}

int main()
{
    ques16_14();
}