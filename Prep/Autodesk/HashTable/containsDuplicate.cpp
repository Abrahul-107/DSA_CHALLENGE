#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool containsDuplicate(vector<int>&arr)
{
    unordered_map<int,int>mp;

    for(auto it:arr)
    {
        mp[it]++;
        if(mp[it]>1)
            return true;

    }
    return false;
}


int main()
{
    vector<int>v={1,2,3,4,1};
    cout<<containsDuplicate(v);


    return 0;
}