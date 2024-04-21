#include<bits/stdc++.h>
using namespace std;

int moveElementsToEnd(vector<int>&a,int n)
{
    int i=0,j=0;
    while(i<n && j<n)
    {
        if(a[j]!=0)
            swap(a[i++],a[j++]);
        else
            j++;
    }

}
int main()
{    
    vector<int>v = {0,5,0,8,9};
    int n = v.size();
    moveElementsToEnd(v, n);
    for(int i=0;i<n;i++)
        cout<<v[i]<<",";

    return 0;
}