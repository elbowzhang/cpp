#include <iostream>
using namespace std;

int intSum(initializer_list<int> i)
{
    int sum = 0;
    for(auto val : i){
        sum += val;
    }
    return sum;
}

int main()
{
    cout << intSum({1,2,3,4,5}) << endl;
}