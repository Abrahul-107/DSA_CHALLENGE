#include<bits/stdc++.h>
using namespace std;

string sortCharByFrequency(string s)
{
    string ans = "";
    unordered_map<char,int>ump;
    for(auto it:s)
        ump[it]++;
    priority_queue<pair<int,char>>pq;

    for(auto it:ump)
        pq.push({it.second,it.first});
    while(!pq.empty())
    {
        int frequency = pq.top().first;
        char character = pq.top().second;
        while(frequency--)
            ans += character;
        pq.pop();
    }
    return ans;

}


int main()
{
    string s = "tree";
    string afterSortByFrequency = sortCharByFrequency(s);
    cout<<"After sort by frequency string is "<<afterSortByFrequency<<endl;
    return 0;
    

}