//https://codeforces.com/contest/816/problem/B
#include<bits/stdc++.h>
using namespace std;

const int maxn = 200007;
int n,k,q;
int a[maxn] = {0};
int s[maxn] = {0};

int main()
{
    cin>>n>>k>>q;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x]++;
        a[y+1]--;

    }
    for(int i=1;i<maxn;i++)
    {
        a[i] = a[i] + a[i-1];
        s[i] = s[i-1] + (a[i]>=k);
    }

    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<s[r] - s[l-1]<<"\n";

    }
    return 0;
}