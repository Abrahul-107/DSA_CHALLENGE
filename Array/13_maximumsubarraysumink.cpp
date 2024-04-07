#include <bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int K, vector<int> &Arr, int N)
{
    long curr_sum = 0;
    for (int i = 0; i < K; i++)
        curr_sum += Arr[i];

    long max_sum = curr_sum;

    for (int i = 0, j = K; j < N; j++, i++)
    {
        curr_sum -= Arr[i];
        curr_sum += Arr[j];

        max_sum = max(max_sum,curr_sum);
    }
    return max_sum;
}

int main()
{
    int N = 6, K = 3;
    vector<int> arr = {5, 1, 2, 6, 3, 1};
    cout << maximumSumSubarray(K, arr, N);
    return 0;
}