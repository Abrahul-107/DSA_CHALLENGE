/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

Example 1:
Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

*/

#include <bits/stdc++.h>
using namespace std;

void backtrack(string &S, int index, string path, vector<string> &result)
{
    // Base case: if we've processed the entire string, add the path to result
    if (index == S.length())
    {
        result.push_back(path);
        return;
    }

    // If the current character is a digit, add it as is
    if (isdigit(S[index]))
        backtrack(S, index + 1, path + S[index], result);
    else
    {
        // Explore the lowercase possibility
        backtrack(S, index + 1, path + (char)tolower(S[index]), result);
        // Explore the uppercase possibility
        backtrack(S, index + 1, path + (char)toupper(S[index]), result);
    }
}

void backtracking(string &s, vector<string> &ans, int index)
{
    if (index == s.length())
    {
        ans.push_back(s);
        return;
    }

    // Always call for the next index
    backtracking(s, ans, index + 1);

    // If the character is alphabetic, toggle case and recurse
    if (isalpha(s[index]))
    {
        s[index] = islower(s[index]) ? toupper(s[index]) : tolower(s[index]);
        backtracking(s, ans, index + 1);
        // Restore original case after recursion
        s[index] = islower(s[index]) ? toupper(s[index]) : tolower(s[index]);
    }
}

vector<string> letterCasePermutation(string s)
{
    vector<string> ans;
    backtracking(s, ans, 0);
    return ans;
}

int main()
{
    string s = "a1b2";
    vector<string> res = letterCasePermutation(s);
    for (const auto &str : res)
        cout << str << " ";
    return 0;
}
