#include<bits/stdc++.h>
using namespace std;

// Function to sort the elements of the matrix and return the sorted matrix
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{
    // Flatten the matrix into a 1D vector
    vector<int> forpush;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            forpush.push_back(Mat[i][j]);
        }
    }

    // Sort the flattened vector
    sort(forpush.begin(), forpush.end());

    // Reshape the sorted 1D vector back into a 2D matrix
    vector<vector<int>> sortedMat(N, vector<int>(N));
    int index = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sortedMat[i][j] = forpush[index++];
        }
    }

    return sortedMat;
}

int main()
{

    int N = 4;

    // Input matrix elements
    vector<vector<int>> Mat = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};

    // Call the sortedMatrix function
    vector<vector<int>> sortedMat = sortedMatrix(N, Mat);

    cout << "Sorted matrix:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sortedMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
