//https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1
#include<iostream>
#include<vector>
#include<map>


using namespace std;


//sweep line technique
int minMeetingRoom(vector<int>&start,vector<int>&end)
{
    map<int,int>mp;
    int size = start.size();
    for(int i=0;i<size;++i)
    {
        mp[start[i]]++;
        mp[end[i]]--;
    }
    int overlap = 0;
    int maxOverlap = 0;

    for(auto it:mp)
    {
        overlap += it.second;
        maxOverlap = max(maxOverlap,overlap);
    }
    return maxOverlap;
}

int main()
{
    vector<int>start = {1, 10, 7};
    vector<int>end = {4, 15, 10};
    cout<<minMeetingRoom(start,end);

    return 0;
}