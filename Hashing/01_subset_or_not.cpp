#include<bits/stdc++.h>
using namespace std;

bool isSubset(vector<int>&arr1,vector<int>&arr2)
{
    unordered_set<int>hashset(arr1.begin(),arr1.end());
    for(auto num:arr2)
    {
        if(hashset.find(num)==hashset.end())
            return false;
    }
    return true;
}

int main()
{
    vector<int>arr1= {1,2,3,4,5,6,7};
    vector<int>arr2 = {1,2,4,6};

    if(isSubset(arr1,arr2))
        cout<<"SUBSET"<<endl;
    else
        cout<<"Not a SUBSET";

    return 0;
}