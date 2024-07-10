#include<bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<int>>&arr,int n,int m)
{
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int ans = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i-1][j-1])
            {
                dp[i][j] = 1+ min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                ans = max(dp[i][j],ans);
            }
            
        }

    }
    return ans;
    
}


int main()
{
    vector<vector<int>>arr = { {0, 1, 1, 0, 1}, 
                                {1, 1, 0, 1, 0},
                                {0, 1, 1, 1, 0},
                                {1, 1, 1, 1, 0},
                                {1, 1, 1, 1, 1},
                                {0, 0, 0, 0, 0}};
	int n = arr.size();
	int m = arr[0].size();
	int ans = maximalSquare(arr,n,m);
    cout<<"Total maximum square is: "<<ans<<endl;

	return 0;

}