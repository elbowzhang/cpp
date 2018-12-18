#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>

using namespace std;

void question10_6()
{
    vector<int> ivec;
    //fill_n(ivec.begin(),10,0);
    fill_n(back_inserter(ivec),10,0);
    for (auto i = ivec.begin(); i != ivec.end(); i++)
        cout << *i;
}

void ques10_7()
{
    vector<int> vec;
    list<int> lst;
    int i;
    while(cin >> i)
        lst.push_back(i);
    copy(lst.cbegin(), lst.cend(), back_inserter(vec));

    for (auto i = lst.begin(); i != lst.end(); i++)
        cout << *i;
    cout << endl;
    for (auto i = vec.begin(); i != vec.end(); i++)
        cout << *i;
}

void ques10_9()
{
    vector<string> svec = {"qwe","qw","qw","the","the","hello"};

    sort(svec.begin(), svec.end());
    auto end_unique = unique(svec.begin(),svec.end());
    svec.erase(end_unique, svec.end());

    for (auto i = svec.begin(); i != svec.end(); i++)
        cout << *i << " ";
}

int main()
{
    // vector<int> ivec = {1,2,3,4,5,6,7,8};
    // vector<double> dvec = {1.1,1.1,2.2};

    // auto result = accumulate(ivec.cbegin(), ivec.cend(), 0);
    // auto result1 = accumulate(dvec.cbegin(), dvec.cend(), 0.0);

    // cout << result << " " << result1 << endl;
    //question10_6();
    ques10_9();
}