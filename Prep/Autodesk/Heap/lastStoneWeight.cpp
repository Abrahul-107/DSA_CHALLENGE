#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int lastStoneWeight(vector<int>& stones) 
{
    priority_queue<int>maxHeap(stones.begin(),stones.end());
    while (maxHeap.size()>1)
    {
        int y = maxHeap.top();maxHeap.pop();
        int x = maxHeap.top();maxHeap.pop();
        if(x!=y)
            maxHeap.push(y-x);
        
    }
    
    return maxHeap.top();

}

int main()
{
    vector<int>arr = {2,7,4,1,8,1};
    cout<<lastStoneWeight(arr);

    return 0;


}