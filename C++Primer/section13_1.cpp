#include <iostream>
using namespace std;

class Employee
{
    private:
        static int sn;
        string name;
        int mysn;

    public:
        Employee() { mysn = sn++; }
        Employee(const string &s) 
        { 
            name = s;
            mysn = sn++;
        }
        Employee(const Employee &e) {
            name = e.name;
            mysn = sn++;
        }
        Employee& operator= (Employee &rhs)
        {
            name = rhs.name;
            return *this;
        }
        const string &get_name() { return name; }
        int get_mysn() { return mysn; }
};

int Employee::sn = 0;

void f1(Employee &s)
{
    cout << s.get_name() << " : " << s.get_mysn() << endl;
}

void exercise13_18()
{
    Employee a("zhao"), b = a, c;
    c = b;
    f1(a);
    f1(b);
    f1(c);
}

class HasPtr
{
    public:
        HasPtr(const string &s = string()) : ps(new string(s)), i(0){ }
        ~HasPtr() { delete ps; }

      private:
        string *ps;
        int i;
};

class numbered
{
    private:
        static int seq;
    public:
        numbered() { mysn = seq++; }
        numbered(numbered &n) { mysn = seq++; }
        int mysn;
};

int numbered::seq = 0;

void f(const numbered &s)
//void f(numbered s)
{
    cout << s.mysn << endl;
}

void exercise13_17()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}

int main()
{
    exercise13_18();
}