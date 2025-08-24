//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


//By using twoPointer(tc:O(N) sc:O(1))
//Space optimized with  single pass
vector<int>twoSumArraySortedOptimized(vector<int>&arr,int target)
{
    int size = arr.size();
    int firstPointer = 0;
    int secondPointer = size-1;

    while(firstPointer<secondPointer)
    {
        int sum = arr[firstPointer] + arr[secondPointer];
        if(sum == target)
            return {firstPointer,secondPointer};
        else if(sum<target)
            firstPointer++;
        else
            secondPointer--;

    }
    return {-1,-1};

}

//By using Hashmap(tc:O(N) sc:O(N))
vector<int>twoSumArraySortedBruteForce(vector<int>&arr,int target)
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



int main()
{

    vector<int>arr = {2,7,11,15};
    int target = 22;
    vector<int>ans = twoSumArraySortedOptimized(arr,target);
    for(auto it:ans)
        cout<<it<<" ";



    return 0;

}