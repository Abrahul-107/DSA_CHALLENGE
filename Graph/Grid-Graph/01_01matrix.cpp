#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void updateMatrix(vector<vector<int>>&mat)
{
    int rowSize = mat.size();
    int colSize = mat[0].size();
    
    queue<pair<int,int>>q;


    for(int i=0;i<rowSize;++i)
    {
        for(int j=0;j<colSize;++j)
        {
            if(mat[i][j]==0)
                q.push({i,j});
            else
                mat[i][j] = -1;

        }
    }

    int delRow[4] = {0,0,-1,1};
    int delCol[4] = {-1,1,0,0};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0;i<4;++i)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow>=0 && nCol>=0 && nRow<rowSize && nCol<colSize && mat[nRow][nCol]==-1)
            {
                mat[nRow][nCol] = mat[row][col]+1;
                q.push({nRow,nCol});
            }
        }

    }
    
}


int main()
{
    vector<vector<int>>matrix = {{0,0,0},{0,1,0},{1,1,1}};
    updateMatrix(matrix);

    for(int i=0;i<matrix.size();++i)
    {
        for(int j=0;j<matrix[0].size();++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}