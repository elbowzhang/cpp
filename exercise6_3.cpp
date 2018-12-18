#include <iostream>
#include <vector>
using namespace std;

typedef int arrt[10];
using arrt = int[10];

arrt *func(int i)
{
}

//尾置返回
auto fuc(int i) -> int (*)[10]
{
}

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) *arrPtr(int i) //&
{
    return (i % 2) ? &odd : &even; //del &
}

//返回一个包含10个string对象的数组指针
string (*func1())[10];

//使用类型别名
using arrt1 = string[10];
arrt1 *func2();

//使用尾置声明
auto func3() -> string (*)[10];

//使用decltype
string str[10];
decltype(str) &func4();

bool str_subrange(const string &str1, const string &str2)
{
    if (str1.size() == str2.size())
        return str1.size() == str2.size();

    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
            return true;
    }
    //no error
}

int &get(int *arry, int index)
{
    return arry[index];
}

void print(vector<int> vInt, unsigned index)
{
    unsigned sz = vInt.size();
    if (!vInt.empty() && index < sz)
    {
        cout << vInt[index] << endl;
        print(vInt, index + 1);
    }
}

int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
    {
        get(ia, i) = i;
        //cout << ia[i] << endl;
    }
    vector<int> ib = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //print(ib, 0);

    cout << *arrPtr(2)[0] << endl;
}