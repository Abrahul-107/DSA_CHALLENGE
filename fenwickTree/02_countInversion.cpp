//https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <bits/stdc++.h>
using namespace std;

int getSum(int i, const vector<int>& fenwick) 
{
    int sum = 0;
    for (; i > 0; i -= (i & (-i))) 
        sum += fenwick[i];  
    
    return sum;
}

void update(vector<int>& fenwick, int i, int x) 
{
    for (; i < fenwick.size(); i += (i & (-i))) 
        fenwick[i] += x;  
    
}

// Function to count inversions in the array
long long int inversionCount(long long arr[], int n) {
    long long int count = 0;
    
    vector<int> fenwick(n + 1, 0);

    // Coordinate compression to handle large values in arr
    vector<long long> sorted_arr(arr, arr + n);
    sort(sorted_arr.begin(), sorted_arr.end());  // Sort the array for compression
    unordered_map<long long, int> rank_map;

    // Assign ranks to the values in sorted order
    int rank = 1;
    for (long long value : sorted_arr)
    {
        if (rank_map.find(value) == rank_map.end()) 
            rank_map[value] = rank++;  // Assign a unique rank to each value
        
    }

    // Update the array to use the compressed values
    for (int i = 0; i < n; ++i) 
        arr[i] = rank_map[arr[i]];  // Replace the original value with its rank
    

    // Count inversions with double call 
    /* for(int i=1;i<=n;i++)
    {
        count += getSum(arr[n-1],fenwick) - getSum(arr[i-1],fenwick);
        update(fenwick,arr[i-1]+1,1);
    

    }*/
    //Count inversion with single call
    for (int i = n - 1; i >= 0; --i) 
    {
        // Count the number of elements already in Fenwick Tree that are less than arr[i]
        count += getSum(arr[i] - 1, fenwick);
        // Add the current element to the Fenwick Tree
        update(fenwick, arr[i], 1);
    }

    return count;
}

int main() {
    
    int n = 5;
    long long arr[] = {2, 4, 1, 3, 5};

    long long int result = inversionCount(arr, n);
    cout << result << endl;  

    return 0;
}
