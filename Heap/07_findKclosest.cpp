//https://leetcode.com/problems/find-k-closest-elements/description
#include<bits/stdc++.h>
using namespace std;

vector<int>findClosestElements(vector<int>&arr,int k,int x)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int n = arr.size();
    for(int i=0;i<n;i++)
        pq.push({abs(x-arr[i]) , arr[i]});
    
    vector<int>ans;
    while (k--)
    {
        arr.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());

    return ans;
    
}

int main()
{
    vector<int>arr = {1,2,3,4,5};
    int k=4 ;
    int x = 3;



    return 0;
}