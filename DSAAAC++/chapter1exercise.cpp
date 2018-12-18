#include <iostream>
#include <vector>
using namespace std;

int selection(vector<int> &vi)
{
    int k = vi.size() / 2;
    for (int i = 0; i < vi.size(); i ++)
    {
        for (int j = i + 1; j < vi.size(); j++)
        {
            if(vi[i] < vi[j])
            {
                int tmp = vi[i];
                vi[i] = vi[j];
                vi[j] = tmp;
            }
        }
    }
    return vi[k];
}

void printOut(int n)
{
    if(n >= 10)
        printOut(n / 10);
    cout << n % 10;
}

void printDigit(double num)
{
    if(num < 0){
        cout << "-";
        num = -num;
    }
    int intPart = num;
    double fract = num - intPart;

    printOut(intPart);
    if(fract == 0)
        return;
    cout << ".";
    //cout << fract;
    while(fract > 0)
    {
        fract *= 10;
        cout << (int)fract;
        fract = fract - (int)fract;
    }
}

void ques1()
{
    vector<int> vi = {7,4,8,12,0,8,56,3,5,1};
    cout << selection(vi);
}

void ques3()
{
    printDigit(-12.1312312);
}

int main()
{
    ques3();
}