#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


int returnSingleNumber(vector<int>&arr)
{
    unordered_map<int,int>mp;
    for(auto it:arr)
        mp[it]++;
    for(auto it:arr)
    {
        if(mp[it]==1)
            return it;
    }
    return 0;


}

int main()
{

    vector<int>arr = {2,4,2,2};
    cout<<returnSingleNumber(arr);
    return 0;

}