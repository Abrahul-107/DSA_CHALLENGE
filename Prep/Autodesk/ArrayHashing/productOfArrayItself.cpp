#include<iostream>
#include<vector>

using namespace std;

vector<int> productArrayItself(vector<int> &arr)
{
    int product = 1;
    int index = -1;
    int zeroCount = 0;
    for(int i=0;i<arr.size();++i)
    {
        if(arr[i]==0)
        {
            index = i;
            zeroCount++;
        }
        else
        {
            product *= arr[i];
        }
    }
    vector<int>ans(arr.size(),0);
    if (zeroCount == 0)
    {
       for(int i=0;i<arr.size();++i)
       {
            ans[i] = product/arr[i];
       }
    }
    else if(zeroCount == 1)
        ans[index] = product;
    return ans;
    

}


int main()
{
    vector<int> arr = {1,2,3,4};
    vector<int> ans = productArrayItself(arr);
    for(auto it: ans)
        cout<<it<<" ";
    
    return 0;

}