/*Time complexity = 0(LogN)
  Space complexity = 0(1)*/
  
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(int arr[], int n)
{
	int left = 0;
	int right = n-1;
	int mid;

	while (left <= right) {
	
		// compute mid by right shifting.
		mid = (left + right) >> 1;
	
		// edge case handle
		if ((mid == 0 || arr[mid - 1] <= arr[mid])
			and (mid == n - 1 || arr[mid + 1] <= arr[mid]))
			break;
	
		// move the right pointer
		if (mid > 0 and arr[mid - 1] > arr[mid])
			right = mid - 1;
	
		// move the left pointer
		else
			left = mid + 1;
	}

	return mid;
}

int main()
{
	int arr[] = { 1, 3, 22, 54, 11, 0 };
	int N = sizeof(arr) / sizeof(arr[0]);
	cout << "Index of a peak point is " << findPeakElement(arr, N);
	return 0;
}

