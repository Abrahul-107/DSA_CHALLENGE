#include<bits/stdc++.h>
using namespace std;

class TreeNode
{


public:
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int val):data(val),left(nullptr),right(nullptr){};

};

int numTreeRecursion(int n)
{
	if(n<=1)
		return 1;
	int ans = 0;

	for(int i=1;i<=n;i++)
	{
		ans += numTreeRecursion(i-1)*numTreeRecursion(n-i);
	}
	return ans;
}

int numTreeMemo(int n,vector<int>&dp)
{
	if(n<=1)
		return 1;
	if(dp[n]!= -1)
		return dp[n];
	int res = 0;

	for(int i=1;i<=n;i++)
	{
		res += numTreeMemo(i-1,dp)*numTreeMemo(n-i,dp);
	}
	return dp[n] = res;

}


int main()
{
	int n =3;
	vector<int>ans;
	cout<<numTreeRecursion(n);
	cout<<numTreeMemo(n,ans);

	return 0;
}
