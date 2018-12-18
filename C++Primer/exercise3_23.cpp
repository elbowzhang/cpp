#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> i(10,5);

    for(auto it = i.begin(); it != i.end(); it ++)
        *it = (*it) * (*it);
    
    for(auto j : i)
        cout << j << endl;
}