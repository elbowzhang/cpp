#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    vector<int> ivec = {1,2,3,4,56,12,1,1,2,2,3,4,5,6,7,7};
    list<string> slist = {"1","1"};

    auto result = count(ivec.cbegin(), ivec.cend(), 2);
    auto result1 = count(slist.cbegin(), slist.cend(), "1");

    cout << result << result1 << endl;
}