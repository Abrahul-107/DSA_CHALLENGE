#include<iostream>
#include<vector>
 
using namespace std;
int maxRob(vector<int>&arr,int left,int right)
{
    if(left==right)
        return arr[left];
    if(left+1 == right)
        return max(arr[left],arr[right]);
    
    int prev2 = arr[left];
    int prev = max(arr[left],arr[left+1]);
    int maxRob = 0;

    for(int i=left+2;i<=right;i++)
    {   
        maxRob += max(prev,arr[i]+prev2);
        prev2 = prev;
        prev = maxRob;
    }
    return prev;

}
int main()
{
    vector<int>arr = {1,2,3,1};
    // first get the maxRob of index0 to size-2 {1,2,3}
    // Second we have to get the maxRob of index1 to size-1 (2,3,1)
    cout<<max(maxRob(arr,0,arr.size()-2),maxRob(arr,1,arr.size()-1));


    return 0;
}