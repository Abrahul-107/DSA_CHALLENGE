#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int rottingOranges(vector<vector<int>>&grid)
{
    int rowSize = grid.size();
    int colSize = grid[0].size();

    int visited[rowSize][colSize];
    queue<pair<pair<int,int>,int>>q;

    for(int i=0;i<rowSize;++i)
    {
        for(int j=0;j<colSize;++j)
        {
            if(grid[i][j] == 2)
            {
                q.push({{i,j},0});
                visited[i][j] = 2;
            }
            else
                visited[i][j] = 0;
        }
    }

    /*
    2 1 1
    1 1 0
    0 1 1
    */

    vector<int>delRow = {0,0,-1,1};
    vector<int>delCol = {-1,1,0,0}; 

    int maxTime = 0;

    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;

        q.pop();

        for(int i=0;i<4;i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow>=0 && nCol>=0 && nRow<rowSize && nCol<colSize && grid[nRow][nCol]==1 && !visited[nRow][nCol])
            {
                q.push({{nRow,nCol},time+1});
                visited[nRow][nCol] = 2;
            }

        }
        maxTime = max(maxTime,time);
    }

    for(int i=0;i<rowSize;++i)
    {
        for(int j=0;j<colSize;++j)
        {
            if(grid[i][j] == 1 & visited[i][j]==0)
                return -1;
        }
    }
    return maxTime;

    
}


int main()
{
    vector<vector<int>>grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout<<rottingOranges(grid); //op should be 4

    return 0;
}