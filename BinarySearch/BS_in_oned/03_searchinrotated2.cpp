#include<bits/stdc++.h>
using namespace std;

bool searchInRotated2(int *nums, int size,int target) 
{
        int left = 0;
        int right = size - 1;

        while (left <= right)
        {
            int mid = left + (right-left) / 2;
            if(nums[mid]==target)
            return true;
            
            if((nums[left] == nums[mid]) && (nums[right] == nums[mid]))
            {
                left++;
                right--;
            }

            else if(nums[left]<=nums[mid])
            {
                if(nums[left]<=target && target<nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                if(nums[mid]<target && target<=nums[right])
                    left = mid + 1;
                else
                   right = mid-1;
            }
        
        }
        return false;
}

int main()
{
    int arr[] = {2,5,6,0,0,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = searchInRotated2(arr, n, 0);

    cout << ans << endl;

    return 0;
}
