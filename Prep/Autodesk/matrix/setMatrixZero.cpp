#include<iostream>
#include<vector>


using namespace std;

void setMatrixZero(vector<vector<int>>&matrix)
{
    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    vector<int>rowMark(rowSize,0);
    vector<int>colMark(colSize,0);

    for(int i=0;i<rowSize;++i)
    {
        for(int j=0;j<colSize;++j)
        {
            if(matrix[i][j]==0)
            {
                rowMark[i] = 1;
                colMark[j] = 1;
            }
            
        }
    }

    for(int i=0;i<rowSize;++i)
    {
        for(int j=0;j<colSize;++j)
        {
            if(rowMark[i] || colMark[j])
                matrix[i][j] = 0;
        }
    }
}


int main()
{
    vector<vector<int>>matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    setMatrixZero(matrix);
    for(int i=0;i<matrix.size();++i)
    {
        for(int j=0;j<matrix[0].size();++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}