//https://codeforces.com/gym/102961/problem/C
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    vector<int>weight(n);

    for(int i=0;i<n;i++)
        cin>>weight[i];

    sort(weight.begin(),weight.end());
    int i=0,j = n-1;
    int ans = 0;

    while(i<=j)
    {
        if(weight[i]+weight[j]>k)
            j--;
        else
            i++,j--;
        ans++;
    }

    cout<<ans<<" ";

    return 0;
}