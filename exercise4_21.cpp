#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
    vector<int> cInt;
    srand((unsigned)time(NULL));
    for(int i = 0; i < 10; i++){
        cInt.push_back(rand() % 100);
        cout << cInt[i] << " ";
    }
    cout << endl;
    for(auto &i : cInt)
        cout << ((i % 2) ? (i * 2) : i) << " ";

    int grade = 60;
    cout << ((grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade < 60) ? "fail" : "low pass");
}