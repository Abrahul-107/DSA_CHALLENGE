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

void backtracking(vector<string> &ans, int i, string &S)
{
    if (i == S.length())
    {
        ans.push_back(S);
    }
    else
    {
        if (isalpha(S[i]))
        { // If it's a letter
            S[i] = toupper(S[i]);
            backtracking(ans, i + 1, S); // Uppercase branch
            S[i] = tolower(S[i]);
            backtracking(ans, i + 1, S); // Lowercase branch
        }
        else
        {
            backtracking(ans, i + 1, S); // Skip non-letters
        }
    }
}
vector<string> letterCasePermutation(string s)
{
    vector<string> ans;
    backtracking(ans, 0, s);
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
