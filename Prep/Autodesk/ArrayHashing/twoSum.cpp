#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>&arr,int target)
{
    unordered_map<int,int>mp;

    for(int i=0;i<arr.size();++i)
    {
        int rest = target - arr[i];
        if(mp.find(rest)!=mp.end())
            return {mp[rest],i};
        mp[arr[i]] = i;
    }
    return {-1,-1};
}

int main()
{
    vector<int>arr = {2,7,11,15};
    int target = 9;
    vector<int>ans = twoSum(arr,target);
    for(auto it:ans)
        cout<<it<<" ";

    return 0;
}