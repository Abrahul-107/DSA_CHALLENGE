#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum element in an array
int maxi(int *arr, int n)
{
    int maxim = INT_MIN; // Initialize maxim to the smallest possible integer value
    // Iterate through the array to find the maximum element
    for (int i = 0; i < n; i++)
        maxim = max(arr[i], maxim); // Update maxim if a larger element is found
    return maxim;                   // Return the maximum element
}

// Function to calculate the total hours required with given maximum hours per day
int calculateHr(int *arr, int n, int mid)
{
    int totalhr = 0; // Initialize total hours to 0
    // Iterate through the tasks and calculate the total hours required
    for (int i = 0; i < n; i++)
    {
        // Calculate the hours required for the current task and add it to total hours
        totalhr += ceil(double(arr[i]) / double(mid));
    }
    return totalhr; // Return the total hours required
}

int main()
{
    int arr[] = {3, 6, 7, 11};            
    int n = sizeof(arr) / sizeof(arr[0]); 
    int h = 8;                            

    int low = 1;             
    int high = maxi(arr, n); 

    // Binary search loop to find the minimum number of hours required per task
    while (low <= high)
    {
        int mid = low + (high - low) / 2;         
        int totalhour = calculateHr(arr, n, mid); // Calculate the total hours required with given maximum hours per day
        // If the total hours required is less than or equal to the available hours,
        // decrease the upper bound to search for a smaller value
        if (totalhour <= h)
            high = mid - 1;
        // If the total hours required exceeds the available hours,
        // increase the lower bound to search for a larger value
        else
            low = mid + 1;
    }

    cout << low << endl; // Output the minimum number of hours required per task

    return 0;
}
