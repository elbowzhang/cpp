#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HasPtr{
    friend void swap(HasPtr &, HasPtr &);

    public:
        HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
        HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { }
        HasPtr &operator=(const HasPtr &);
        string &operator*();
        bool operator<(const HasPtr &) const;
        ~HasPtr();

    private:
        string *ps;
        int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newps = new string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}

string& HasPtr::operator*()
{
    return *ps;
}

bool HasPtr::operator<(const HasPtr &rhs) const
{
    return *ps < *rhs.ps;
}

HasPtr::~HasPtr()
{
    delete ps;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

void exer13_30()
{
    HasPtr h1("h1111");
    HasPtr h2("h2222");
    swap(h1, h2);
    cout << "h1---" << *h1 << endl;
}

void exer13_31()
{
    vector<HasPtr> vh;
    vh.push_back(HasPtr("b"));
    vh.push_back(HasPtr("a"));
    vh.push_back(HasPtr("f"));
    vh.push_back(HasPtr("c"));
    vh.push_back(HasPtr("q"));
    cout << "before swap" << endl;
    for(auto p : vh)
        cout << *p << endl;
    sort(vh.begin(), vh.end());
    cout << "after swap" << endl;
    for(auto p : vh)
        cout << *p << endl;
}

int main()
{
    exer13_31();
    return 0;
}