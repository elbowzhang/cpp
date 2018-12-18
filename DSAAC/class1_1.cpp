#include <iostream>
#include <vector>
using namespace std;

//选择问题，选择N个数字中最大的第k个数
//3 4 9 1 7 12 0 4 16 19 8 第6个数即7
int findKinN1(vector<int> iv, int k)
{
    int temp;
    for (int i = 0; i < iv.size(); ++i){
        for (int j = i + 1; j < iv.size(); ++j){
            if(iv[i] > iv[j]){
                temp = iv[i];
                iv[i] = iv[j];
                iv[j] = temp;
            }
        }
    }
    return iv[k-1];
}

int findKinN2(vector<int> iv, int k)
{
    int temp;
    int re;
    for (int i = 0; i < k; ++i){
        for (int j = i+1; j < k; ++j){
            if(iv[i] > iv[j]){
                temp = iv[i];
                iv[i] = iv[j];
                iv[j] = temp;
            }
        }
    }
    re = iv[k - 1];
    for (int i = k; i < iv.size(); ++i){
        if(iv[i] < iv[k]){
            for (int j = 0; j < k; ++j){
                //
            }
        }
    }
}

void ques1_3(int i){
    if(i < 0){
        cout << "-";
        i = -i;
    }
    if(i >= 10)
        ques1_3(i / 10);
    cout << i % 10;
}

int main()
{
    vector<int> iv = {3,4,9,1,7,12,0,4,16,19,8};
    int k = findKinN1(iv, 7);
    //cout << k;
    ques1_3(-1213);
}