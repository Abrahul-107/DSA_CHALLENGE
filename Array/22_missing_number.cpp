/*https://leetcode.com/problems/missing-number/description/*/
#include<bits/stdc++.h>
using namespace std;

int findMissing(int *arr,int n)
{
    int ans = 0;
    for(int i=0;i<n;i++)
        ans = ans ^ arr[i] ^ i;
    return ans^n;
}
int main()
{
    int arr[] = {0,1,3};
    int n = 3;
    int ans = findMissing(arr,n);

    cout<<ans;
    return 0;
}