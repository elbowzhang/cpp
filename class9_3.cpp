#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <forward_list>

using namespace std;

void question9_18()
{
    //在deque的首尾添加元素的性能很好
    string input;
    deque<string> sdeque;

    while(cin >> input)
        sdeque.push_back(input);
    for (auto si = sdeque.begin(); si != sdeque.end(); si ++)
        cout << *si << endl;
}

void question9_19()
{
    //使用list在首尾添加元素性能基本和上题一样
    string input;
    list<string> slist;
    while(cin >> input)
        slist.push_back(input);
    for (auto si = slist.begin(); si != slist.end(); si++)
        cout << *si << endl;
}

void question9_20()
{
    list<int> ilist = {1,2,3,4,5,6,7,8,9};
    deque<int> even_d, odd_d;

    for (auto iter = ilist.begin(); iter != ilist.end(); iter ++){
        if(*iter % 2)
            even_d.push_back(*iter);
        else
            odd_d.push_back(*iter);
    }
}

void question9_21()
{
    string input;
    vector<string> svector;

    auto iter = svector.begin();
    while(cin >> input)
        iter = svector.insert(iter,input);      //insert操作会插入到指定迭代器的前一个元素的位置

    for(auto sveci = svector.begin(); sveci != svector.end(); sveci ++)
        cout << *sveci << endl;
}

void question9_26()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> ivector;
    list<int> ilist;

    ivector.assign(ia,ia+11);   //赋值
    ilist.assign(ia,ia+11);

    vector<int>::iterator iiv = ivector.begin();
    while(iiv != ivector.end()){
        if(!(*iiv % 2)) //偶数
            iiv = ivector.erase(iiv);
        else
            iiv++;
    }

    list<int>::iterator iil = ilist.begin();
    while(iil != ilist.end()){
        if (*iil % 2)   //奇数
            iil = ilist.erase(iil);
        else
            iil++;
    }

    for (iiv = ivector.begin(); iiv != ivector.end(); iiv ++)
        cout << *iiv << endl;

    for (iil = ilist.begin(); iil != ilist.end(); iil ++)
        cout << *iil << endl;
}

void question9_27()
{
    forward_list<int> iflist = {1,2,3,4,5,6,7,8,9};

    auto prev = iflist.before_begin();
    auto curr = iflist.begin();

    while(curr != iflist.end()){
        if(*curr % 2){
            cout << *curr << endl;
            curr = iflist.erase_after(prev);
        }
        else{
            prev = curr;
            curr++;
        }
    }
}

void question9_28(forward_list<string> &sflist, const string &s1, const string &s2)
{
    auto prev = sflist.before_begin();
    auto curr = sflist.begin();
    bool inserted = false;

    while(curr != sflist.end()){
        if(*curr == s1){
            curr = sflist.insert_after(curr, s2);
            inserted = true;
        }
        prev = curr;
        curr++;
    }

    if(!inserted)
        sflist.insert_after(prev, s2);
}

//list 和 forward_list不能用+=的原因是它的存储不是连续空间，只能使用++实现迭代器移动
void question9_31()
{
    list<int> ilist = {1,2,3,4,5,6,7,8,9};
    auto curr = ilist.begin();

    while(curr != ilist.end()){
        if(*curr % 2){
            curr = ilist.insert(curr, *curr);
            curr++;
            curr++;
        }
        else
            curr = ilist.erase(curr);
    }
    for (curr = ilist.begin(); curr != ilist.end(); curr ++)
        cout << *curr << endl;

    //前向链表需要维护两个迭代器
    forward_list<int> iflist = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = iflist.before_begin();
    auto curr1 = iflist.begin();

    while(curr1 != iflist.end()){
        if(*curr1 % 2){
            curr1 = iflist.insert_after(curr1, *curr1);
            prev = curr1;
            curr1++;
        }
        else
            curr1 = iflist.erase_after(prev);
    }

    for (curr1 = iflist.begin(); curr1 != iflist.end(); curr1 ++)
        cout << *curr1 << endl;
}

void question9_34()
{
    vector<int> vi = {1,2,3,4,5,6,7,8,9};
    vector<int>::iterator iter = vi.begin();
    while(iter != vi.end()){
        if(*iter % 2){
            iter = vi.insert(iter, *iter);
            ++iter;
        }
        ++iter;
    }

    for (iter = vi.begin(); iter != vi.end(); iter++)
        cout << *iter << endl;
}

int main()
{
    //question9_18();
    //question9_21();
    //question9_27();

    // forward_list<string> testflist = {"hello","world","!"};
    // string s1 = ("hell");
    // string s2 = ("!!");
    // question9_28(testflist, s1, s2);

    // for (auto curr = testflist.cbegin(); curr != testflist.cend(); curr ++)
    //     cout << *curr;

    //question9_31();

    question9_34();
}