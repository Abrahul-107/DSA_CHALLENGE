//https://www.naukri.com/code360/problems/longest-repeating-substring_980523
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestRepeatingSubstring(string s,int k)
{
    int left = 0 , maxLen = 0,maxFreq = 0;
    unordered_map<char,int>freq;
    int n = s.length();
    for(int right =0;right<n;++right)
    {
        freq[s[right]]++;
        maxFreq = max(maxFreq, freq[s[right]]);
        int windowSize = right - left + 1;
        /*windowSize - maxFreq: This represents the number of characters in the 
        current window that need to be replaced to make all characters the same. */
        if(windowSize-maxFreq>k)
        {
            freq[s[left]]--;
            left++;
        }
        maxLen = max(maxLen, right - left +1);
    }
    
    return maxLen;

}

int main()
{
    string s;
    cin>>s;
    int k;cin>>k;
    cout<<longestRepeatingSubstring(s,k);
    return 0;
}