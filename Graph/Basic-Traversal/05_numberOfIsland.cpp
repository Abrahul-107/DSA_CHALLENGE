#include<iostream>
#include<vector>

using namespace std;


void dfs(vector<vector<string>>&grid,int row,int col,int rowSize,int colSize)
{
    if(row>=rowSize || col>=colSize || row<0 || col<0 || grid[row][col]=="0")
        return ;
    
    grid[row][col] = "0";

    dfs(grid,row+1,col,rowSize,colSize);
    dfs(grid,row-1,col,rowSize,colSize);
    dfs(grid,row,col+1,rowSize,colSize);
    dfs(grid,row,col-1,rowSize,colSize);


}

int numOfIsland(vector<vector<string>>&grid)
{
    int count = 0;

    int rowSize = grid.size();
    int colSize = grid[0].size();

    for(int row=0;row<rowSize;++row)
    {
        for(int col=0;col<colSize;++col)
        {
            if(grid[row][col] == "1")
            {
                dfs(grid,row,col,rowSize,colSize);
                count++;
            }
        }
    }
    return count;


}

int main()
{
    vector<vector<string>>grid = {
        {"1","1","1","1","0"},
        {"1","1","0","1","0"},
        {"1","1","0","0","1"},
        {"0","0","0","1","0"}
        };
    cout<<numOfIsland(grid);


    return 0;
}