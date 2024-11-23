#include<bits/stdc++.h>
using namespace std;

int sumInRange(int l,int r,vector<int>&arr,int n)
{
    int prefix[n+1];
    prefix[0] = 0;
    for(int i=1;i<=n;++i)
        prefix[i] = prefix[i-1]+arr[i-1];
    
    return prefix[r] - prefix[l-1];
    
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for (int i = 0; i < n; i++)
    {
        int val ;cin>>val;
        arr.push_back(val);
    }
    int l,r;cin>>l>>r;
    cout<<sumInRange(l,r,arr,n);

    return 0;


}