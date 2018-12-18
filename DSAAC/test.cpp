#include <iostream>
using namespace std;

void p(int n)
{
    if(n == 1)
    {

    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if(n % i == 0)
            {
                cout << i << "*";
                p(n / i);
                break;
            }
        }
    }
}

int main()
{
    int i;
    cin >> i;
    p(i);
}