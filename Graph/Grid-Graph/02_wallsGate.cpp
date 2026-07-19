//https://neetcode.io/solutions/walls-and-gates
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void islandAndTreasire(vector<vector<int>>&grid)
{

    int rowSize = grid.size();
    int colSize = grid[0].size();

    queue<pair<int,int>>q;

    for(int i=0;i<rowSize;++i)
    {
        for(int j=0;j<colSize;++j)
        {
            if(grid[i][j]==0)
                q.push({i,j});
        }
    }

    int delRow[4] = {-1,1,0,0};
    int delCol[4] = {0,0,-1,1};

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow<rowSize && nCol<colSize && nRow>=0 && nCol>=0 && grid[nRow][nCol]==2147483647)
            {
                grid[nRow][nCol] = grid[row][col] + 1;
                q.push({nRow,nCol});
            }
        }
    }

}


int main()
{
    vector<vector<int>>grid = {
        {2147483647,-1,0,2147483647},
        {2147483647,2147483647,2147483647,-1},
        {2147483647,-1,2147483647,-1},
        {0,-1,2147483647,2147483647}
        };
    
    islandAndTreasire(grid);

    for(int i=0;i<grid.size();++i)
    {
        for(int j=0;j<grid[0].size();++j)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}