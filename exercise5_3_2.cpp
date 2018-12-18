#include <iostream>
using namespace std;

int main()
{
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    int spaceCnt = 0, tabCnt = 0, newlineCnt = 0;

    char ch;

    while(cin.get(ch)){
        switch(ch){
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
            default:
                break;
        }
    }
    cout << "a" << aCnt << endl;
    cout << "e" << eCnt << endl;
    cout << "o" << oCnt << endl;
    cout << "u" << uCnt << endl;
    cout << " " << spaceCnt << endl;
    cout << "\\t" << tabCnt << endl;
    cout << "\\n" << newlineCnt << endl;
}