//https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
#include<iostream>
#include<vector>
#include <climits>

using namespace std;

int maxSubarraySum(vector<int>& arr, int k) 
{
    int firstPointer=0,secondPointer=0;
    long long maxSum = INT_MIN;
    long long sum = 0;

    while(secondPointer<arr.size())
    {
        sum += arr[secondPointer];
        if(secondPointer-firstPointer+1<k)
            secondPointer++;
        else if(secondPointer-firstPointer+1 == k)
        {
            maxSum = max(sum,maxSum);
            sum -= arr[firstPointer];
            firstPointer++;secondPointer++;
        }
    }
    return maxSum;
}


int main()
{

    vector<int>arr = {100,200,300,400};
    int k = 2;

    //Output should be 700
    cout<<maxSubarraySum(arr,k);




    return 0;
}