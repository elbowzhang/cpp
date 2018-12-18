#include <iostream>
#include <vector>
using namespace std;

//use pointer
void swap(int *p, int *q)
{
    int i = *p;
    *p = *q;
    *q = i;
}

//use reference
void swap1(int &p,int &q)
{
    int i = p;
    p = q;
    q = i;
}

int main()
{
    int i = 1,j = 2;
    cout << i << " " << j << endl;
    swap(&i,&j);
    cout << i << " " << j << endl;
    swap1(i,j);
    cout << i << " " << j << endl;
}

//bool compare(matrix&,matrix&);
//vector<int>::iterator change_val(int,vector<int>::iterator);