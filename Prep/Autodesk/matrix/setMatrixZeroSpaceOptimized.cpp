#include<iostream>
#include<vector>


using namespace std;

void setMatrixZero(vector<vector<int>>&matrix)
{
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    int col0 = 1;

    for(int i=0;i<rowSize;i++)
    {
        for(int j=0;j<colSize;j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if(j!=0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for(int i=1;i<rowSize;++i)
    {
        for(int j=1;j<colSize;++j)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if(matrix[0][0] == 0)
    {
        for(int j=0;j<colSize;j++)
            matrix[0][j] = 0;
    }
    if(col0==0)
    {
        for(int i=0;i<rowSize;i++)
            matrix[i][0] = 0;
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