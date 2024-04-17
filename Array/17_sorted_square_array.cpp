#include<bits/stdc++.h>
using namespace std;

vector<int> sortedSquaredArray(vector<int>&arr)
{
    int n = arr.size();
    int left=0,right=n-1;
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--)
    {
        int multileft = arr[left]*arr[left];
        int multiright = arr[right]*arr[right];
        if(multileft>multiright)
        {
            ans[i]=multileft;
            left++;
        }
        else
        {
            ans[i]=multiright;
            right--;
        }     
    }
    return ans;


}


int main()
{
    vector<int> v = {-4,-1,0,3,10};
    vector<int>ans = sortedSquaredArray(v);
    for(auto it:ans)
        cout<<it<<" ";

    return 0;
}