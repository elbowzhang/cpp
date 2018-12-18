#include <iostream>
using namespace std;

int main()
{
    string str("hello,,,hello");

    for(auto& c : str)
    {
        if(!ispunct(c))
            cout << c;
    }

    const string s = "keep out";
    for(auto& c : s){}
        //不改变c值时合法
}