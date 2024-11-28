//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
#include<bits/stdc++.h>
using namespace std;

int withoutStack(string s)
{
    int open_count = 0;
    int close_count = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(')
            open_count++;
        else
        {
            if(open_count>0)
                open_count --;
            else
                close_count ++;
        }
        
    }
    return open_count + close_count;
}

int usingStack(string s)
{
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        if(!st.empty() && s[i]==')' && st.top() == '(')
            st.pop();
        else
            st.push(s[i]);

    }
    return st.size();

}


int main()
{
    string s;
    cin>>s;
    
    cout<<withoutStack(s);
    cout<<usingStack(s);

    return 0;
}