#include<bits/stdc++.h>
using namespace std;

vector<int> productOfArrayExceptItself(int *arr,int n)
{
    vector<int>ans;
    int prod = 1;
    for(int i=0;i<n;i++)
        prod *= arr[i];
    
    for(int i=0;i<n;i++)
        ans.push_back(prod/arr[i]);
    return ans;
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>v = productOfArrayExceptItself(arr,n);
    for(auto it:v)
        cout<<it<<" ";

    return 0;

}