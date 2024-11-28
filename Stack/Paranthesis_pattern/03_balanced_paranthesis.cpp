#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {                                            // Iterate through each character in the string
        char ch = s[i];                          // Get the current character
        if (ch == '(' || ch == '{' || ch == '[') // If the current character is an opening parenthesis, curly brace, or square bracket
            st.push(ch);                         // Push it onto the stack
        else
        { 
            // If the current character is a closing parenthesis, curly brace, or square bracket
            if (!st.empty())
            {                                    // If the stack is not empty
                char top = st.top();             // Get the top element of the stack
                if ((ch == ')' && top == '(') || // If the current character matches the corresponding opening character at the top of the stack
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    st.pop(); // Pop the top element from the stack
                }
                else
                {                 // If the current character does not match the corresponding opening character at the top of the stack
                    return false; // Return false, as the string is invalid
                }
            }
            else
            {                 // If the stack is empty
                return false; // Return false, as the string is invalid (no opening character to match with)
            }
        }
    }
    return st.empty(); // If the stack is empty, all opening characters have been matched, so return true; otherwise, return false
}

int main()
{
    string input;
    cout << "Enter a string containing parentheses, curly braces, and square brackets: ";
    cin >> input; 
    if (isValid(input))
    {
        cout << "The string has valid parentheses, curly braces, and square brackets." << endl;
    }
    else
    {
        cout << "The string does not have valid parentheses, curly braces, and square brackets." << endl;
    }
    return 0;
}
