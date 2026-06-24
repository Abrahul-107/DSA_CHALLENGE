#include<iostream>
#include<stack>
using namespace std;

bool validParanthesis(string s)
{
    stack<char>st;

    for(int i=0;i<s.length();++i)
    {
        char ch = s[i];
        if(ch=='(' || ch =='{' || ch=='[')
            st.push(ch);
        else
        {
            if(!st.empty())
            {
                char sTop = st.top();
                if((ch==')' && sTop=='(') || (ch=='}' && sTop=='{') || (ch==']' && sTop=='['))
                    st.pop();
                else
                    return false;
            }
            else
                false;
        }
    }
    if(st.empty())
        return true;
    else
        return false;

}

int main()
{
    string s = "()[]{}";
    cout<<validParanthesis(s);

    return 0;

}
