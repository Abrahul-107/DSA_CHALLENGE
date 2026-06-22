#include<iostream>
using namespace std;

bool validAnagram(string s,string t)
{
    int lenS = s.length();
    int lenT = t.length();

    if(lenS!=lenT)
        return false;
    
    int arr[26] = {0};
    for(int i=0;i<lenS;++i)
    {
        arr[s[i]-'a']++;
        arr[t[i]-'a']--;
    }
    for(auto it:arr)
    {
        if(it!=0)
            return false;
    }
    return true;
}


int main()
{
    string s = "rahul";
    string t = "luhar";
    cout<<validAnagram(s,t);


    return 0;
}