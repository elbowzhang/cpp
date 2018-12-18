#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> strs;
    string str;
    while(cin >> str)
    {
        strs.push_back(str);
    }
    for(auto& s : strs)
    {
        for(auto& c : s)
        {
            c = toupper(c);
        }
    }
    for(auto s : strs)
        cout << s << endl;
}