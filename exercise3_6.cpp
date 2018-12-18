#include <iostream>
using namespace std;

int main()
{
    string str("abcd");
    for(char& c:str)
        c = 'X';
    cout << str;

    decltype(str.size()) index = 0;
    while(index < str.size()){
        str[index] = 'A';
        index ++;
    }
    cout << str;

    string s;
    cout << s[0] << endl;
}