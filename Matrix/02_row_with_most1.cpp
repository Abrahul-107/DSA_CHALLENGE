#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
{
	    
	   
	    int maxOnesRow = -1; // Initialize the row index with maximum 1s to -1
        int maxOnesCount = 0; // Initialize the maximum count of 1s to 0

        // Iterate through each row
        for(int i = 0; i < n; i++)
        {
            int onesCount = 0; // Initialize the count of 1s in the current row to 0

            // Iterate through each column in the current row
            for(int j = 0; j < m; j++)
            {
                // If the current element is 1, increment the count of 1s
                if(arr[i][j] == 1)
                    onesCount++;
            }

            // If the count of 1s in the current row is greater than the maximum count of 1s
            // Update the maximum count of 1s and the row index with maximum 1s
            if(onesCount > maxOnesCount)
            {
                maxOnesCount = onesCount;
                maxOnesRow = i;
            }
        }

        // Return the row index with maximum 1s
        return maxOnesRow;
}



int main()
{
    vector<vector<int>> matrix = {{1 ,0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
    int row = 3;
    int col = 4;
    cout<<rowWithMax1s(matrix,row,col);

    return 0;

}