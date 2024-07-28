// 1823. Find the Winner of the Circular Game leetcode

#include <bits/stdc++.h>
using namespace std;

// recursive approach
int findTheWinnerr(int n, int k)
{
    if (n == 1)
        return 0;
    return (findTheWinnerr(n - 1, k) + k) % n;
}

// Iterative approach
int findTheWinner(int n, int k)
{
    int ans = 0;
    for (int i = 2; i <= n; i++)
        ans = (ans + k) % i;

    return ans;
}

int main()
{
    int n = 6;
    int k = 5;
    cout << findTheWinnerr(n, k) + 1;
    cout << findTheWinner(n, k) + 1;

    return 0;
}