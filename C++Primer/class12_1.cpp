#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include "StrBlob.h"
//#include "StrBlobPtr.h"

using namespace std;

void shared_ptrEg()
{
    shared_ptr<string> p1 = make_shared<string>();
    if(p1 && p1->empty())
        *p1 = "hi";
    cout << *p1 << endl;
    shared_ptr<list<int>> p2;

    shared_ptr<int> p3 = make_shared<int>(10);
    cout << *p3 << endl;

    shared_ptr<string> p4 = make_shared<string>(10,'9');
    cout << *p4 << endl;
}

void ques12_2()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() << endl;
    }
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;
}

vector<int> *new_vector()
{
    return new (nothrow) vector<int>;
}

void read_ints(vector<int> *pv)
{
    int v;
    while(cin >> v)
        pv->push_back(v);
}

void print_ints(vector<int> *pv)
{
    for(auto &v:*pv)
        cout << v << " ";
    cout << endl;
}

void ques12_6()
{
    vector<int> *pv = new_vector();
    read_ints(pv);
    print_ints(pv);
    delete pv;
    pv = nullptr;
}



int main()
{
    ques12_6();
}