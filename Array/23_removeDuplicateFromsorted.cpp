#include<bits/stdc++.h>
using namespace std;

int removeDuplicateFromSorted(vector<int>&arr)
{
    int n = arr.size();
    if(n==0 && n==1)
        return n;
    int j = 0;

    for(int i=0;i<n-1;i++)
        if(arr[i]!=arr[i+1])
        arr[j++] = arr[i];
    arr[j++] = arr[n-1];
    return j;
}

int main()
{
    vector<int>arr = {1,2,2,3,4,4,6,8,8,9};
    int n = removeDuplicateFromSorted(arr);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    return 0;
    
}