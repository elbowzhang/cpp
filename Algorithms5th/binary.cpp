#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &iv, int key)
{
    int lo = 0, hi = iv.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(key < iv[mid])
            hi = mid - 1;
        else if(key > iv[mid])
            lo = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{

}