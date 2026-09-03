#include<iostream>

using namespace std;


int minFlipMonIncrOptimized(string s)
{
    int size = s.size();
    int countOne = 0;
    int flip = 0;

    
    for(int i=0;i<size;++i)
    {
        if(s[i]=='1')
            countOne++;
        else
        {
            flip = min(1+flip,countOne);
        }
    }
    return flip;
    
}

int solve(string &s,int currIndex, int prevVal)
{
    if(currIndex >= s.size())
        return 0;
    
    int flip = INT_MAX;
    int notFlip = INT_MAX;

    if(s[currIndex] == '0')
    {
        if(prevVal == 1)
            flip = 1 + solve(s,currIndex+1,1);
        else
        {
            flip = 1 + solve(s,currIndex+1,1);
            notFlip = solve(s,currIndex+1,0);
        }
    }
    else
    {
        if(prevVal == 1) //11
            notFlip = solve(s,currIndex+1,1);
        else
        {
            flip = 1 + solve(s,currIndex+1,0);
            notFlip = solve(s,currIndex+1,1);
        }
        

    }
    return min(flip,notFlip);

}

int minFlipMonIncr(string s)
{
    return solve(s,0,0);
    
}


int main()
{
    string s = "00110";
    cout<<minFlipMonIncrOptimized(s);

    return 0;
}