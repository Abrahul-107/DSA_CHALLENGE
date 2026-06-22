#include<iostream>
using namespace std;

bool isPalindrome(string s)
{
    int start = 0;
    int end = s.length()-1;
    while (start<=end)
    {
        if(!isalpha(s[start]))
        {
            start++;continue;
        }
        if(!isalpha(s[end]))
        {
            end--;continue;
        }
        if(tolower(s[start]) != towlower(s[end]))
        return false;
        else{
        start++;end--;
        }
    }
    return true;
    
}


int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout<<isPalindrome(s);

    return 0;

}