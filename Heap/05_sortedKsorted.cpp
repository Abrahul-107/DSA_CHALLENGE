#include <bits/stdc++.h>
using namespace std;

vector<int> sortKsortedArray(vector<int>& arr, int k) 
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> ans;
    
    for(int i=0;i<k+1 && i<arr.size();i++)
        minHeap.push(arr[i]);

    for(int i=k+1;i<arr.size();i++)
    {
        minHeap.push(arr[i]);
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    // Pop the remaining elements from the heap to the result array
    while (!minHeap.empty()) 
    {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return ans;
}

int main() 
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    vector<int> res = sortKsortedArray(arr, k);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    
    return 0;
}
