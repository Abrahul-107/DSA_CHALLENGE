#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>&arr,int k)
{
    priority_queue<int>maxHeap;

    for(int i=0;i<arr.size();i++)
    {
        maxHeap.push(arr[i]);
        if(maxHeap.size()>k)
            maxHeap.pop();
    }
    return maxHeap.top();

}

int main()
{
    vector<int>arr = {1,4,2,9,7,5};
    int k = 3;
    int ans = kthSmallest(arr,k);
    cout<<ans;


    return 0;

}