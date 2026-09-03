#include<iostream>

using namespace std;

int dfs(vector<vector<int>>&grid,int row,int col,int rowSize,int colSize)
{
    if(row<0 || col<0 || row>=rowSize || col>=colSize || grid[row][col] == 0)
        return 0;
    grid[row][col] = 0;

    return 1+ dfs(grid,row+1,col,rowSize,colSize)+
              dfs(grid,row-1,col,rowSize,colSize)+
              dfs(grid,row,col-1,rowSize,colSize)+
              dfs(grid,row,col+1,rowSize,colSize);
}

int maxAreaIsland(vector<vector<int>>&grid)
{
    int rowSize = grid.size();
    int colSize = grid[0].size();
    int maxArea = 0;

    for(int i=0;i<rowSize;++i)
    {
        for(int j=0;j<colSize;++j)
        {
            if(grid[i][j] == 1)
                maxArea = max(maxArea,dfs(grid,i,j,rowSize,colSize));

        }
    }
    return maxArea;
}


int main()
{
    vector<vector<int>> grid = {
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout<<maxAreaIsland(grid); // output should be 6

    return 0;
}