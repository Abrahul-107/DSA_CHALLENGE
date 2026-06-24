#include<iostream>
#include<vector>
using namespace std;

int maxRobWithDp(vector<int>&arr)
{
    int size = arr.size();
    vector<int>dp(size,0);
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);

    for(int i=2;i<size;++i)
        dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
        
    return dp[size-1];


}

int maxRob(vector<int>&arr)
{
    int size = arr.size();
    vector<int>dp(size,0);
    int prev2 = arr[0];
    int prev1 = max(arr[0],arr[1]);
    int maxRob = 0;

    for(int i=2;i<size;++i)
    {
        maxRob = max(prev1,prev2+arr[i]);
        prev2 = prev1;
        prev1 = maxRob;
    }
    return prev1;


}





int main()
{
    vector<int>arr  = {1,2,3,1};
    cout<<maxRob(arr);
    return 0;


}