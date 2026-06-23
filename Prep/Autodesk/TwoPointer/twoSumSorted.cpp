#include<iostream>
#include<vector>
using namespace std;

vector<int>twoSum(vector<int>&arr,int target)
{
    int start = 0;
    int end = arr.size()-1;

    while(start<end)
    {
        int sum = arr[start] + arr[end];
        if(sum<target)
            start++;
        if(sum==target)
            return{start,end};
        if(sum>target)
            end--;
        

    }
    return {-1,-1};
}

int main()
{
    vector<int>arr = {2,7,11,15};
    vector<int>ans = twoSum(arr,9);
    for(auto it:ans)
        cout<<it<<" ";
    
    return 0;
}