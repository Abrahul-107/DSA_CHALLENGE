#include<bits/stdc++.h>
using namespace std;

//Bruteforce approach
void setMatrixZero(vector<vector<int>>&matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int>row(m,0);
    vector<int>col(n,0);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(row[i]||col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}







//Optimized with space at constant space (in place algo)
void setMatrixToZero(vector<vector<int>>&matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int column0 = 1;


    // First pass: mark rows and columns that need to be zeroed
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==0)
            { 
                matrix[i][0] = 0;// Mark the first column of the current row
                if(j!=0)
                    matrix[0][j] = 0;// Mark the first row of the current column
                else
                    column0 = 0; // Mark that the first column needs to be zeroed
            }
        }
    }

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(matrix[i][0]==0 || matrix[0][j]==0)
            { 
                matrix[i][j] = 0;
            }
        }
    }
    if(matrix[0][0]==0)
        for(int j=0;j<n;j++)
            matrix[0][j] = 0;
    if(column0==0)
        for(int i=0;i<m;i++)
            matrix[i][0]=0;


}

int main()
{
    vector<vector<int>>matrix = {{1,1,1},{1,0,1},{1,1,1}};

    //Bruteforce with O(M)+O(N) space complexity 
    // setMatrixZero(matrix);
    

    //Optimized with space 
    setMatrixToZero(matrix);
    int m = matrix.size();
    int n =  matrix[0].size();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}