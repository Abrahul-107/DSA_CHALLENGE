#include <bits/stdc++.h>
using namespace std;

// Function to search for a target value in a sorted matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    // Get the number of rows in the matrix
    int m = matrix.size();
    // If the matrix is empty, return false
    if (m == 0) return false;
    // Get the number of columns in the matrix
    int n = matrix[0].size();
    // Initialize left pointer to the start of the matrix and right pointer to the end
    int left = 0, right = m * n - 1;

    // Binary search loop
    while (left <= right) 
    {
        // Calculate the middle index
        int mid = left + (right - left) / 2;
        // Calculate the value at the middle index in the matrix
        int mid_val = matrix[mid / n][mid % n];

        // If the middle value is equal to the target, return true
        if (mid_val == target)
            return true;
        // If the middle value is less than the target, update the left pointer
        else if (mid_val < target)
            left = mid + 1;
        // If the middle value is greater than the target, update the right pointer
        else
            right = mid - 1;
    }
    // If the target is not found, return false
    return false;
}

int main() {
    // Test matrix
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    // Target value to search for
    int target = 3;

    // Call the searchMatrix function to check if the target exists in the matrix
    if (searchMatrix(matrix, target))
        cout << "Target found in the matrix." << endl;
    else
        cout << "Target not found in the matrix." << endl;

    return 0;
}
