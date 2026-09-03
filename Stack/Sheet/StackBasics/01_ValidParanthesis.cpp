#include<iostream>
#include<stack>

using namespace std;

bool isValid(string s)
{
    stack<char>st;

    for(int i=0;i<s.length();i++)
    {
        char currentChar = s[i];
        if(currentChar == '('  || currentChar=='{' || currentChar=='[')
            st.push(currentChar);
        else
        {
            if(st.empty())
                return false;
            if(st.top()=='(' && currentChar!=')') return false;
            if(st.top()=='{' && currentChar!='}') return false;
            if(st.top()=='[' && currentChar!=']') return false;

            st.pop();
            
        }
    }
    return st.empty();
}


int main()
{
    string s = "()[]{}";
    cout<<isValid(s);


    return 0;
}