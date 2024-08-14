//https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
#include<bits/stdc++.h>
using namespace std;

/*
Here we finds the k-th smallest pair distance in an array by calculating all pairwise distances, 
storing them in a max heap, and ensuring the heap size does not exceed k. The k-th smallest distance is
then the maximum element in the heap.....
 */
int findKthSmallestPairDistance(vector<int>&arr,int k)
{
    priority_queue<int>maxHeap;
    int size = arr.size();

    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            int checkAns = abs(arr[i]-arr[j]);
            maxHeap.push(checkAns);
            if(maxHeap.size()>k)
                maxHeap.pop();
        }
    }
    return maxHeap.top();


}
//Time complexity = O(N*N)for nested iteration + O(NlogK)for heap

int main()
{
    vector<int>arr = {1,3,1};
    int k = 1;

    cout<<findKthSmallestPairDistance(arr,k);
    return 0;
}