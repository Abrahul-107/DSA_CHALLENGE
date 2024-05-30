#include<bits/stdc++.h>
using namespace std;

vector<int>subarraySumIndex(int *arr,int n,int s)
{
    int i=0,j=0,sum=0;

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];

        while(sum>s && j<i)
        {
            sum -= arr[j];
            j++;
        }
        if(sum==s)
            return {j+1,i+1};

    }
    return {-1};

}
int main()
{
    int n,s;
    cin>>n>>s;

    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int>ans = subarraySumIndex(arr,n,s);

    for(auto &it:ans)
        cout<<it<<" ";

    return 0;
}