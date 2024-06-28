//https://leetcode.com/problems/maximum-total-importance-of-roads/description
#include<bits/stdc++.h>
using namespace std;

long long maximumImportance(vector<vector<int>>&roads,int n)
{
    vector<long long>degree(n,0);
    for(auto &vector:roads)
    {
        degree[vector[0]]++;
        degree[vector[1]]++;

    }
    sort(degree.begin(),degree.end());
    long long ans = 0;
    for(int i=0;i<n;i++)
        ans+=(i+1)*degree[i];
    return ans;
}

int main()
{
    int num_of_city = 5;
    vector<vector<int>>roads = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    int ans = maximumImportance(roads,num_of_city);
    cout<<"Total maximum sum is "<<ans<<endl;

    return 0;

}