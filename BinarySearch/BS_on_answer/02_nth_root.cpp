#include <bits/stdc++.h>
using namespace std;

int possibleroot(int mid, int nthroot, int num)
{
    long long ans = 1;
    for (int i = 1; i <= nthroot; i++)
    {
        ans *= mid;
        if (ans > num)
            return -1; // Return -1 if the answer exceeds the given number
    }
    if (ans == num)
        return 1;
    return 0;
}

int nthRootOfNumber(int num, int nthroot)
{
    int low = 1, high = num;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int chk = possibleroot(mid, nthroot, num);
        if (chk == 1)
            return mid;
        else if (chk == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int num;
    int nthroot;
    cin >> num >> nthroot;

    int ans = nthRootOfNumber(num, nthroot);

    cout << ans << endl;

    return 0;
}
