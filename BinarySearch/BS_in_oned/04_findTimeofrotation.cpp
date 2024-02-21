#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) 
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high]) 
        {
            ans = min(ans, arr[low]);
            index = low;
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) 
        {
            ans = min(ans, arr[low]);
            index = low;
            // Eliminate left half:
            low = mid + 1;
        }
        else 
        { 
            //if right part is sorted:
            ans = min(ans, arr[mid]);
            index = mid;
            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}
