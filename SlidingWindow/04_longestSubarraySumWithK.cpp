//https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
#include<iostream>
using namespace std;

int longestSubarrayWithSumK(vector<int>arr,int k)
{
    

}


int main()
{
    int n;cin>>n;vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x; 
        arr.push_back(x);
    }
    int k;cin>>k;
    cout<<longestSubarrayWithSumK(arr,k);




    return 0;
}