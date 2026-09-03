#include<iostream>
#include<iostream>
#include<queue>


using namespace std;

int maxDistance(vector<vector<int>>&grid)
{
    int rowSize = grid.size();
    int colSize = grid[0].size();

    queue<pair<int,int>>q;

    for(int i=0;i<rowSize;++i)
    {
        for(int j=0;j<colSize;++j)
        {
            if(grid[i][j]==1)
            {
                q.push({i,j});
                grid[i][j] = 0;
            }
            else
                grid[i][j] = -1;
        }
    }
    if (q.empty() || q.size() == rowSize * colSize)
            return -1;

        int delRow[4] = {-1,1,0,0};
        int delCol[4] = {0,0,-1,1};

        int maxDist = 0;

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;++i)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow>=0 && nCol>=0 && nRow<rowSize && nCol<colSize && grid[nRow][nCol]==-1)
                {
                    grid[nRow][nCol] = grid[row][col]+1;
                    maxDist = max(maxDist, grid[nRow][nCol]);
                    q.push({nRow, nCol});
                }
            }
        }

    return maxDist;

}

int main()
{

    vector<vector<int>>grid = {{1,0,1},{0,0,0},{1,0,1}};
    cout<<maxDistance(grid);
    
    return 0;
}