#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void print(vector<int> vInt, unsigned index)
{
    unsigned sz = vInt.size();
#ifndef NDEBUG
    cout << "vector size:" << sz << endl;
#endif
    if (!vInt.empty() && index < sz)
    {
        cout << vInt[index] << endl;
        print(vInt, index + 1);
    }
}

int main()
{
    if (0)
        cerr << "Error " << __FILE__
             << " : in function " << __func__
             << " : in line " << __LINE__;

    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(v, 0);
}