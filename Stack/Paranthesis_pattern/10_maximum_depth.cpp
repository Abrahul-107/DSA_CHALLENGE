//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s)
{
    int c = 0;
    auto maxm = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            c++;
            maxm = max(maxm,c);
        }
        else if(s[i]==')')
            c--;
    }
    return maxm;

}

int main()
{
    string s;cin>>s;
    cout<<maxDepth(s);


    return 0;
}