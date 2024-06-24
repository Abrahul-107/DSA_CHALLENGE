#include<bits/stdc++.h>
using namespace std;

vector<int> kthLargestReturn(vector<int>&arr,int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0;i<arr.size();i++)
    {
        minHeap.push(arr[i]);
        if(minHeap.size()>k)
            minHeap.pop();

    }
    vector<int>ans;
    for(int i=0;i<k;i++)
    {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    return ans;

}


int main()
{
    vector<int>arr = {1,4,2,9,7,5};
    int k = 3;
    vector<int>ans = kthLargestReturn(arr,k);
    for(int i=0;i<k;i++)
        cout<<ans[i]<<" ";

    return 0;


}