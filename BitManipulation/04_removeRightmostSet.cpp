#include<bits/stdc++.h>
using namespace std;

int removeRightMostSetBit(int n)
{
    return n -(n&(-n));
}

int main()
{
    int n = 6;
    int ans = removeRightMostSetBit(n);
    cout<<ans;

    return 0;
}