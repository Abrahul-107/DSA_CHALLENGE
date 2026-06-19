//https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
#include<iostream>
#include<vector>
#include<unordered_map>
#include <climits>

using namespace std;

int maxSubarraySum(vector<int>& arr, int k) 
{
    int i = 0, j = 0;
    int size = arr.size();

    unordered_map<int,int>freq;
    long long sum = 0;
    long long maxSum = INT_MIN;

    while(j<size)
    {
        sum += arr[j];
        freq[arr[j]]++;

        if(j-i+1 > k)
        {
            sum -= arr[i];
            freq[arr[i]]--;
            if(freq[arr[i]] == 0)
                freq.erase(arr[i]);
            i++;
        }
        if(j-i+1 ==k && freq.size() == k )
            maxSum = max(sum,maxSum);
        j++;

    }
    return maxSum;
}


int main()
{

    vector<int>arr = {1,5,4,2,9,9,9};
    int k = 3;

    cout<<maxSubarraySum(arr,k);




    return 0;
}