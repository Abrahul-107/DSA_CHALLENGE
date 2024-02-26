#include<bits/stdc++.h>
using namespace std;

int findSqrt(int val)
{
    long long low = 0;
    long long high = val;

    while (low<=high)
    {
        long long mid = low+(high-low)/2;
        if(mid*mid==(long long)val)
        return mid;
        if(mid*mid<=val)
            low = mid+1;
        else 
            high = mid-1;
        
    }
    return -1;
    

}

int main()
{
    int val;
    cin>>val;
    int ans = findSqrt(val);

    cout << ans << endl;

    return 0;
}