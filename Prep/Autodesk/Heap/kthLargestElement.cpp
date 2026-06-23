#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int kthLargest(vector<int>& arr,int k) 
{
    priority_queue<int>maxHeap(arr.begin(),arr.end());
    k = k-1;
    while(k--)
        maxHeap.pop();
    
    return maxHeap.top();

}

int main()
{
    vector<int>arr = {2,7,4,1,8,1};
    cout<<kthLargest(arr,3);

    return 0;


}