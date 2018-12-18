#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> iv;
    int i;
    int count = 0;
    while(cin >> i)
        iv.push_back(i);

    sort(iv.begin(), iv.end());

    for (i = 0; i < iv.size() - 2; ++i){
        int j = i + 1;
        int k = iv.size() - 1;

        while (j < k){
            int sum = iv[i] + iv[j] + iv[k];
            if(sum == 0){
                count++;
                cout << iv[i] << " " << iv[j] << " " << iv[k] << endl;
            }
            if(sum >= 0)
                --k;
            else
                ++j;
        }
    }
    cout << count;
}