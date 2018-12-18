#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <functional>
#include <algorithm>
#include <iterator>

using namespace std;

void testExample()
{
    list<int> lst = {1,2,3,4};
    list<int> lst1, lst2;
    copy(lst.cbegin(), lst.cend(), front_inserter(lst1));
    copy(lst.cbegin(), lst.cend(), inserter(lst2, lst2.begin()));

    for(auto i:lst1)
        cout << i;

    for(auto i:lst2)
        cout << i;
}

void ques10_26()
{
    vector<int> vi = {1,1,1,2,3,4,4,3};
    list<int> li;
    stable_sort(vi.begin(), vi.end(), [](const int &i1, const int &i2) { return i1 < i2; });
    unique_copy(vi.begin(), vi.end(), back_inserter(li));

    for(auto i:li)
        cout << i;
}

void ques10_29()
{
    ifstream in("people");
    if(!in){
        cout << "open failed" << endl;
        return;
    }

    istream_iterator<string> in_iter(in);
    istream_iterator<string> eof;
    vector<string> words;
    while(in_iter != eof)
        words.push_back(*in_iter++);
    for(auto word:words)
        cout << word << endl;
}

void ques10_30()
{
    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;
    vector<int> vi;
    while(in_iter != eof)
        vi.push_back(*in_iter++);

    sort(vi.begin(), vi.end());
    ostream_iterator<int> out_iter(cout," ");
    copy(vi.begin(),vi.end(),out_iter);
}

void ques10_31()
{
    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;
    vector<int> vi;
    while(in_iter != eof)
        vi.push_back(*in_iter++);

    sort(vi.begin(), vi.end());
    ostream_iterator<int> out_iter(cout, " ");
    unique_copy(vi.begin(), vi.end(), out_iter);        //删除重复的元素

}

void ques10_36()
{
    vector<int> vi = {1,0,2,3,0,5,0,5,6};
    auto last_zero = find(vi.rbegin(), vi.rend(), 0);
    //将迭代器向容器头推进一个位置
    last_zero++;
    int p = 1;
    for (auto iter = vi.begin(); iter != last_zero.base(); iter++, p++)
        ;
    cout << p;
}

void ques10_37()
{
    vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
    list<int> li;
    vector<int>::reverse_iterator re(vi.begin() + 2);
    vector<int>::reverse_iterator rb(vi.begin() + 7);
    copy(rb,re,back_inserter(li));
    for (auto i:li)
        cout << i << " ";
}

int main()
{
    ques10_37();
}