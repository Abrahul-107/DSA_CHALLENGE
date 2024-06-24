#include<bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s)
{
    stack<int>st;
    int n = s.length();
    unordered_set<int> to_remove; 

    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            st.push(i);
        else if(s[i]==')')
        {
            if(!st.empty() && s[st.top()]=='(')
                st.pop();
            else
                to_remove.insert(i);
        }
    }
    while (!st.empty())
    {
        to_remove.insert(st.top());
        st.pop();
    }
    string result;
    for (int i = 0; i < n; i++) 
        if (to_remove.find(i) == to_remove.end()) 
            result += s[i];
        
    return result;
    
}

int main()
{
    string s = "lee(t(c)o)de)";
    string ans =  minRemoveToMakeValid(s);
    cout<<ans<<endl;

    return 0 ;

}