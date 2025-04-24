//https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
#include<iostream>
#include<deque>
using namespace std;

vector<int>maxInSubarraySizeKBruteforce(vector<int>arr,int k)
{
    vector<int>ans;
    for(int i=0;i<arr.size();i++)
    {
        int maxm = INT_MIN;
        for(int j=i;j<i+k;j++)
        {
            maxm = max(arr[j],maxm);
        }
        ans.push_back(maxm);
    }
    return ans;
}

vector<int>maxInSubarraySizeKOptimized(vector<int>arr,int k)
{
    deque<int>dq;
    vector<int>ans;
    for(int i=0;i<arr.size();i++)
    { 
        if(!dq.empty() && dq.front() == i-k)
            dq.pop_front();
        while(!dq.empty() && arr[dq.back()]<arr[i])
            dq.pop_back();
        dq.push_back(i);
        if(i>=k-1)
            ans.push_back(arr[dq.front()]);
    }
    return ans;
}


int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cin>>k;
    vector<int>ans = maxInSubarraySizeKOptimized(arr,k);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}