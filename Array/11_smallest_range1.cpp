/*Leetcode 908

You are given an integer array nums and an integer k.
In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x
where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.
The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after applying the mentioned operation at most once for each index in it.



Example 1:
Input: nums = [1], k = 0
Output: 0
Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.

Example 2:
Input: nums = [0,10], k = 2
Output: 6
Explanation: Change nums to be [2, 8]. The score is max(nums) - min(nums) = 8 - 2 = 6.

Example 3:
Input: nums = [1,3,6], k = 3
Output: 0
Explanation: Change nums to be [4, 4, 4]. The score is max(nums) - min(nums) = 4 - 4 = 0.


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 104
0 <= k <= 104
*/

#include <bits/stdc++.h>
using namespace std;

int smallestRange1(vector<int> &v, int k)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        mini = min(mini, v[i]);
        maxi = max(maxi, v[i]);
    }

    if (maxi - mini == 0 || (maxi - mini) - (2 * k) <= 0)
        return 0;
    else
        return (maxi - mini) - 2 * k;
}

int main()
{
    int arr[] = {0,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);
    int k = 2;
    cout << smallestRange1(v, k);

    return 0;
}