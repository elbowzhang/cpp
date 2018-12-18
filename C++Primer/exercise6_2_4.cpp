#include <iostream>
using namespace std;

int compare(const int i, const int *j)
{
    return (i > *j) ? i : *j;
}

void printInt(const int *i, const int size)
{
    
    for(int j = 0; j < size; j++)
    {
        cout << *i++ << endl;
    }
}

int main()
{
    int i = 1, j = 2;
    int q[2] = {0,1};
    cout << compare(i, &j) << endl;

    printInt(&i,1);
    printInt(q,2);
}