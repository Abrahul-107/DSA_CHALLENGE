#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermuation(vector<int>&v) 
{
    int n = v.size();
    int ind = -1;

    /*First we have to find Breakpoint */
    for(int i = n-2;i>=0;i--)
    {
        if(v[i]<v[i+1])
        {
            ind = i;
            break;
        }
    }

    /*If break point is not find thn return the reverse*/
    if(ind == -1)
    {
        reverse(v.begin(),v.end());
        return v;
    }

    /* Find the next greater element and swap it with arr[ind]:*/
    for(int i=n-1;i>=0;i--)
    {
        if(v[i]>v[ind])
        {
            swap(v[i],v[ind]);
            break;
        }
    }

    /*Reverse the right half */
    reverse(v.begin()+ind+1,v.end());

    return v;
    
        
}
int main()
{
    int arr[] = {1,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    vector<int>v = nextPermuation(vec);
    for(auto it:v)
        cout<<it<<" ";

    return 0;
    
}