#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int size, int element)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == element)
            return mid;
        else if (arr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 12, 16, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = binarySearch(arr, n, 16);

    cout << ans << endl;

    return 0;
}
