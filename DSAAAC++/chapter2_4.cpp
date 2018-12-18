#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(int n)
{
    int partialSum = 0;

    for (int i = 1; i <= n; ++i)
        partialSum += i * i * i;
    return partialSum;
}

//花费时间O(N3)
int maxSubSum1(const vector<int> & vi)
{
    int maxsum = 0;

    for (int i = 0; i < vi.size(); ++i)
    {
        for (int j = i; j < vi.size(); ++j)
        {
            int thisSum = 0;

            for (int k = i; k < j; ++k)
                thisSum += vi[k];

            if(thisSum > maxsum)
                maxsum = thisSum;
        }
    }
    return maxsum;
}

//花费时间O(N2)
int maxSubSum2(const vector<int> & vi)
{
    int maxsum = 0;

    for (int i = 0; i < vi.size(); ++i)
    {
        int thisSum = 0;
        for (int j = i; j < vi.size(); ++j)
        {
            thisSum += vi[j];
            if(thisSum > maxsum)
                maxsum = thisSum;
        }
    }
    return maxsum;
}

//最大子序列的递归求法
int maxSumRec(const vector<int> & vi, int left, int right)
{
    if(left == right)       //base case
    {
        if(vi[left] > 0)
            return vi[left];
        else
            return 0;
    }

    int center = (left + right) / 2;
    int maxLeftSum = maxSumRec(vi, left, right);
    int maxRightSum = maxSumRec(vi, left, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; --i)
    {
        leftBorderSum += vi[i];
        if(leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int i = center + 1; i <= right; ++i)
    {
        rightBorderSum += vi[i];
        if(rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return (maxLeftSum > maxRightSum && maxLeftSum > maxLeftBorderSum + maxRightBorderSum) ? \
            maxLeftSum : \
            (maxRightSum > maxLeftBorderSum + maxRightBorderSum ? maxRightSum : maxLeftBorderSum + maxRightBorderSum);
}

//递归方式求解最大子序列,花费时间O(NlogN)
int maxSubSum3(const vector<int> & vi)
{
    return maxSumRec(vi, 0, vi.size() - 1);
}

//求解最大子序列时间最快的一种算法，花费的时间是线性时间O(N)
int maxSubSum4(const vector<int> & vi)
{
    int maxSum = 0, thisSum = 0;

    for (int i = 0; i < vi.size(); ++i)
    {
        thisSum += vi[i];
        
        if(thisSum > maxSum)
            maxSum = thisSum;
        else if(thisSum < 0)
            thisSum = 0;
    }

    return maxSum;
}

//折半查找，假设数组排列为从小到大 O(logN)
template <typename T>
T binarySearch(const vector<T> & vi, const T & x)
{
    int left = 0, right = vi.size()-1;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(vi[mid] < x)
            left = mid + 1;
        else if(vi[mid] > x)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

//欧几里得算法,寻找两数的最大公因数 O(logN)
long long gcd(long long m, long long n)
{
    while(n != 0){
        long long rem = m % n;
        m = n;
        n = rem;
    }
    return m;
} 

int main()
{
 
} 