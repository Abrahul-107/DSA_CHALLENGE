//https://leetcode.com/problems/two-sum/description/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//Time complexity : O(N) , Space complexity : 0(N)
//Time optimized reduced to single pass from dual pass of array
vector<int>twoSumOptimized(vector<int>&arr,int target)
{
    unordered_map<int,int>mp ;
    int size = arr.size();

    for(int index=0;index<size;++index)
    {
        int rest = target - arr[index];
        if(mp.find(rest) != mp.end())
            return {mp[rest],index};
        mp[arr[index]] = index;
    }
    return {-1,-1};

}

//Time complexity : O(N^2) , Space complexity : 0(1)
vector<int>twoSumBruteForce(vector<int>&arr,int target)
{
    int size = arr.size();
    vector<int>ans(2,-1);
    for(int index=0;index<size;index++)
    {
        for(int secondPassIndex=1;secondPassIndex<size;++secondPassIndex)
        {
            if(arr[index]+arr[secondPassIndex]==target)
            {
                return {index,secondPassIndex};
            }
        }
    }
    return ans;


}

int main()
{

    vector<int>arr = {1,4,5,6,7,9};
    int target = 14;
    vector<int>ans = twoSumOptimized(arr,target);
    for(auto it:ans)
        cout<<it<<" ";

    return 0;

}