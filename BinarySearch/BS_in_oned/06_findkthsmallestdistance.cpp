#include <bits/stdc++.h>
using namespace std;

/**
 * Function to count the number of pairs with a distance less than or equal to the given distance.
 * @param arr - The sorted array of integers.
 * @param distance - The distance to check pairs against.
 * @return The number of pairs with a distance less than or equal to the given distance.
 */
int slidingWindowCheck(vector<int> &arr, int distance)
{
    int i = 0;
    int pairCount = 0;

    // Sliding window approach to count valid pairs
    for (int j = 1; j < arr.size(); j++)
    {
        while (arr[j] - arr[i] > distance)
        {
            i++;
        }
        pairCount += (j - i);
    }

    return pairCount;
}

/**
 * Function to find the k-th smallest distance pair in the array.
 * @param arr - The array of integers.
 * @param k - The k-th smallest distance to find.
 * @return The k-th smallest distance.
 */
int findKthSmallestDistance(vector<int> &arr, int k)
{
    // Sort the array to use the sliding window technique
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int low = 0;
    int high = arr[n - 1] - arr[0];

    // Binary search on the distance
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int countPair = slidingWindowCheck(arr, mid);

        // Adjust the binary search range based on the pair count
        if (countPair < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid-1;
        }
    }

    // Return the correct k-th smallest distance
    return low;
}

int main()
{
    vector<int> arr = {1, 6, 1};
    int k = 3;
    cout << findKthSmallestDistance(arr, k);

    return 0;
}
