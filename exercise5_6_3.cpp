#include <iostream>
using namespace std;

int main()
{
    int ival1,ival2;
    cin >> ival1 >> ival2;
    if(ival2 == 0){
        cout << "ival";
        throw runtime_error("000");
    }
} 