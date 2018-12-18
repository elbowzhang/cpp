#include <iostream>
using namespace std;

int main()
{
    cout << "char " << sizeof(char) << endl;
    cout << "uchar " << sizeof(unsigned char) << endl;
    cout << "int " << sizeof(int) << endl;
    cout << "uint " << sizeof(unsigned int) << endl;

    int x[10];
    int *p = x;
    cout << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(p)/sizeof(*p) << endl;
}