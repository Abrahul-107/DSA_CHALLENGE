#include<bits/stdc++.h>
using namespace std;

int findTheRightMostSetBit(int n)
{
    return n&(-n);
}

int main()
{
    int n = 6;
    int ans = findTheRightMostSetBit(n);
    cout<<ans;

    return 0;
}