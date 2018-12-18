#include <iostream>
using namespace std;

int main()
{
    int maxCnt = 0, currCnt = 1;
    string preString, currString, maxString;
    while(cin >> currString){
        if(currString == preString){
            ++currCnt;
            if(currCnt > maxCnt){
                maxCnt = currCnt;
                maxString = currString;
            }
        }
        else{
            currCnt = 1;
        }
        preString = currString;
    }
    if(maxCnt > 1)
        cout << maxString << " " << maxCnt << endl;
}