//https://cses.fi/problemset/task/1074
#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5;

int main() 
{
    int N;
    long long sum = 0;
    int p[maxN];

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> p[i];

    sort(p, p + N);

    long long median = p[(N - 1) / 2];

    for (int i = 0; i < N; i++)
        sum += abs(p[i] - median);

    cout << sum << endl;

    return 0;
}
