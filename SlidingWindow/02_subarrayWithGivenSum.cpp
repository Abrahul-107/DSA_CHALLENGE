//https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
#include<iostream>
using namespace std;

vector<int> subarrayWithGivenSum(vector<int>arr,int target)
{
    int sum = 0;
    int left = 0;
    vector<int>ans;
    for(int right=0;right<arr.size();right++)
    {
        sum += arr[right];
        while (target<sum && left<right)
        {
            sum -= arr[left];
            left++;
        }
        if(sum==target)
        {
            ans.push_back(left+1);
            ans.push_back(right+1);
            return ans;
        }
        
    }
    ans.push_back(-1);
    return ans;

}
int main()
{
    vector<int>arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int target;
    cin>>target;
    vector<int>ans = subarrayWithGivenSum(arr,target);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;




}