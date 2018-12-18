#include <iostream>
using namespace std;

class HasPtr
{
    public:
        HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
        HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { }
        HasPtr &operator=(const HasPtr &);
        ~HasPtr();

    private:
        string *ps;
        int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

class HasPtr1
{
    public:
        HasPtr1(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)){ }
        HasPtr1(const HasPtr1 &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
        HasPtr1 &operator=(const HasPtr1&);
        HasPtr1 &operator=(const string &);
        string &operator*();
        ~HasPtr1();

      private:
        string *ps;
        int i;
        size_t *use;
};

HasPtr1::~HasPtr1()
{
    if(--*use == 0)
    {
        delete ps;
        delete use;
    }
}

HasPtr1& HasPtr1::operator=(const HasPtr1& rhs)
{
    ++*rhs.use;     //increment the use of the right-hand operand
    if(--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr1& HasPtr1::operator=(const string& rhs)
{
    *ps = rhs;
    return *this;
}

string& HasPtr1::operator*()
{
    return *ps;
}

void exer13_27()
{
    HasPtr1 h1("asassas");
    cout << "h1---" << *h1 << endl;
    HasPtr1 h2(h1);
    cout << "h2---" << *h2 << endl;
    h1 = "as";
    cout << "h1---" << *h1 << endl;
    cout << "h2---" << *h2 << endl;
}

class TreeNode{
    private:
        string value;
        int count;
        TreeNode *left;
        TreeNode *right;
};

int main()
{
    exer13_27();
    return 1;
}