#include <bits/stdc++.h>
using namespace std;

long long kadensAlgo(int arr[], int n) 
{
    long long maximum = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) 
    {

        sum += arr[i];

        if (sum > maximum) 
            maximum = sum;
        if (sum < 0) 
            sum = 0;
        
    }

    return maximum;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = kadensAlgo(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
