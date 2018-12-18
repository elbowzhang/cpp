#include <iostream>
using namespace std;

int main()
{
    string str("some string");
    // decltype(str.size()) punct_cnt = 0;
    // for(auto c:str)
    //     if(ispunct(c))
    //         ++punct_cnt;
    //     cout << punct_cnt
    //          << "is" << str << endl;
    for(decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); ++index)
        str[index] = toupper(str[index]);
    cout << str << endl;
}