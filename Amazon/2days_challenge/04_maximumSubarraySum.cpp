#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int maximumSubarraySum(vector<int>&arr)
{
    int size = arr.size();
    int maximumSum = INT_MIN;
    int currentSum = 0;
    for(int index = 0;index<size;++index)
    {
        currentSum = currentSum + arr[index];
        if(currentSum>maximumSum)
            maximumSum = currentSum;
        if(currentSum<0)
            currentSum = 0;
    }
    return maximumSum;

}

int main()
{
    vector<int>arr = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = maximumSubarraySum(arr);
    cout<<ans<<endl;


    return 0;

}