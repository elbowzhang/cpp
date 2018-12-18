#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str("some string");
    if(str.begin() != str.end()){
        auto it = str.begin();
        *it = toupper(*it);
    }
    cout << str << endl;

    for(auto iter = str.begin(); iter != str.end() && !isspace(*iter); iter ++)
        *iter = toupper(*iter);

    cout << str << endl;

    vector<string> strs{"123","qwe","asd"};

    for(auto iter1 = strs.cbegin(); iter1 != strs.cend() && !iter1->empty(); ++ iter1)
        cout << *iter1 ;
}