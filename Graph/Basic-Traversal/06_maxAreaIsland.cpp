#include<iostream>
#include<vector>

using namespace std;


int dfs(vector<vector<int>>&grid,int row,int col, int rowSize, int colSize)
{
    if(row<0 || col<0 || row>=rowSize || col>=colSize || grid[row][col] == 0)
        return 0;
    grid[row][col] = 0;

    return 1+dfs(grid,row-1,col,rowSize,colSize) 
    +dfs(grid,row+1,col,rowSize,colSize) 
    +dfs(grid,row,col-1,rowSize,colSize) 
    +dfs(grid,row,col+1,rowSize,colSize);

    
}
int maxAreaOfIsland(vector<vector<int>>&grid)
{
    int rowSize = grid.size();
    int colSize = grid[0].size();

    int maxArea = INT_MIN;

    for(int row=0;row<rowSize;++row)
    {
        for(int col=0;col<colSize;++col)
        {
            if(grid[row][col] == 1)
                maxArea = max(maxArea,dfs(grid,row,col,rowSize,colSize));
        }
    }
    return maxArea;
}

int main()
{
    vector<vector<int>>grid = {
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    cout<<maxAreaOfIsland(grid);



    return 0;
}