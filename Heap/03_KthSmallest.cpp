#include<bits/stdc++.h>
using namespace std;

//Using minHeap for kth smallest
int kthSmallestUsingMinhheap(vector<int>&arr,int k)
{
    priority_queue<int, vector<int>,greater<int>>minHeap;
    int n = arr.size();
    for(int i=0;i<n;i++)
        minHeap.push(arr[i]);
    k = k-1;
    while(k--)
        minHeap.pop();
    return minHeap.top();
}

//Using maxHeap for kth smallest
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
    int ans = kthSmallestUsingMinhheap(arr,k);
    cout<<ans;


    return 0;

}