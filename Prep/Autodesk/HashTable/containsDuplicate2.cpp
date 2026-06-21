#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool containsNearByDuplicate(vector<int>&arr,int k)
{
    unordered_map<int,int>mp;
    int size = arr.size();

    for(int i=0;i<size;++i)
    {
        if(mp.find(arr[i])!=mp.end())
        {
            if(abs(i-mp[arr[i]])<=k)
                return true;
        }

        mp[arr[i]] = i;

    }
    return false;
}


int main()
{
    vector<int>arr = {1,2,3,1};
    int k = 3;
    cout<<containsNearByDuplicate(arr,k);

    return 0;
}