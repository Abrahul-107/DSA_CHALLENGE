#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>


using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string,vector<string>>mp;
    for(auto word:strs)
    {
        string singleWord = word;
        sort(singleWord.begin(),singleWord.end());
        mp[singleWord].push_back(word);
    }
    vector<vector<string>>ans;

    for(auto word:mp)
    {
        ans.push_back(word.second);
    }
    return ans;

}


int main()
{
    vector<string>strs  = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>>ans = groupAnagrams(strs);
    for(auto strarr:ans)
    {
        for(auto word:strarr)
            cout<<word<<" ";
    }

    return 0;
}