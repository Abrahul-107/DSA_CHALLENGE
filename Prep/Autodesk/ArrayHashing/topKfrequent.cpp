#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

vector<int> topKfrequent(vector<int>&arr,int k)
{
    unordered_map<int,int>mp;
    for(auto it:arr)
        mp[it]++;
    
    priority_queue<pair<int,int>>maxHeap;
    for(auto it:mp)
        maxHeap.push({it.second,it.first});
    
    vector<int>ans;
    while (k--)
    {
        ans.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return ans;
    

}


int main()
{
    vector<int>arr = {1,1,1,2,2,3};
    int k = 2;

    vector<int>ans = topKfrequent(arr,k);
    for(auto it:ans)
        cout<<it<<" ";
        

    return 0;
}

