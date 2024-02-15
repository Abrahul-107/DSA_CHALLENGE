/*LEETCODE 2640*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void findPrefixScore(int *arr,int n)
{
    ll maxi = INT_MIN;
    ll prefix_sum = 0;
    vector<int>v;

    for(int i=0;i<n;i++)
    {
        maxi = max(maxi,ll(arr[i]));
        prefix_sum += maxi + arr[i];
        v.push_back(prefix_sum);
    }
    for(auto it:v)
        cout<<it<<" ";
    

}

int main()
{
    int arr[] = {1,1,2,4,8,16};
    int n = sizeof(arr) / sizeof(arr[0]);

    findPrefixScore(arr,n);

    return 0;
}