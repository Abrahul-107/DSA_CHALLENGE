#include<iostream>
#include<vector>
#include<queue>

using namespace std;

string reorganizeString(string s)
{
    vector<int>freq(26,0);
    for(auto ch:s)
        freq[ch-'a']++;
    
    priority_queue<pair<int,char>>maxHeap;
    for(int i=0;i<26;++i)
    {
        if(freq[i]>0)
            maxHeap.push({freq[i],char('a'+i)});
    }

    string ans = "";
    while(maxHeap.size()>=2)
    {
        auto first = maxHeap.top();maxHeap.pop();
        auto second = maxHeap.top();maxHeap.pop();

        ans += first.second;ans += second.second;
        first.first--;second.first--;

        if(first.first>0)
            maxHeap.push(first);
        if(second.first)
            maxHeap.push(second);

    }

    while(!maxHeap.empty())
    {
        auto last = maxHeap.top();
        maxHeap.pop();
        if(last.first>1)
            return "";
        ans += last.second;
    }
    return ans;

}


int main()
{
    string s = "aaabbccb";
    cout<<reorganizeString(s);

    return 0;
}