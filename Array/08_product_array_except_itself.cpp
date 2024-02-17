#include<bits/stdc++.h>
using namespace std;

 vector<int> productExceptSelf(int *arr,int n) {
        
        vector<int> ans(n);
        ans[0] = 1;
        for(int i=1; i<n; i++)
        {
            ans[i] = ans[i-1] * arr[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--)
        {
            ans[i] *= right;
            right *= arr[i];
        }
        return ans;
 }
int main()
{
    int arr[] = {1,2,0,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>v = productExceptSelf(arr,n);
    for(auto it:v)
        cout<<it<<" ";

    return 0;

}