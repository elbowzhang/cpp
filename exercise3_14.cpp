#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> i;
    int c;
    while(cin >> c)
        i.push_back(c);

    for(auto a : i)
        cout << a << endl;
}