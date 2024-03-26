#include<bits/stdc++.h>
using namespace std;

int charToDigit(char x)
{
    return x - '0';
}
char digitToChar(int digit)
{
    return digit + '0';
}

string addNumbers(string a,string b)
{
    // Make sure a is not larger than b
    if(a.length()>b.length())
        swap(a,b);
    
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    string result = "";
    int carry = 0;

    for(size_t i = 0;i<b.length();i++)
    {
        int d1 = (i<a.length())?charToDigit(a[i]):0;
        int d2 = charToDigit(b[i]);

        int sum = d1 + d2 + carry;
        carry = sum/10;
        result.push_back(digitToChar(sum%10));
    }
    if(carry>0)
        result.push_back(digitToChar(carry));
    
    reverse(result.begin(),result.end());
    return result;

}

int main()
{
    string a = "1111111111111111111111111111111111111";
    string b = "2222222222222222222222222222222222222";

    cout<<addNumbers(a,b);

    return 0;
}