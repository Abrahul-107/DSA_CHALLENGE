#include<iostream>
#include<vector>

using namespace std;

int rowSize;
int colSize;
int dRow[4] = {0,0,-1,1};
int dCol[4] = {-1,1,0,0};

void dfs(int row,int col,vector<vector<int>>&heights,vector<vector<bool>>&visited)
{
    visited[row][col] = true;

    for(int i=0;i<4;++i)
    {
        int nRow = row + dRow[i];
        int nCol = col + dCol[i];

        /*
        Original water flow rule

        Water flows from a cell to a neighbour if the neighbour is lower or equal.

        5 → 4 → 3 → Ocean

        The condition is:

        nextHeight <= currentHeight
        What we actually do

        Instead of starting from every cell and seeing if it reaches the ocean, we start from the ocean and move backwards.

        If water can flow

        5 → 4 → Ocean

        then in reverse we can go

        Ocean → 4 → 5

        Notice we're moving from lower to higher.

        Therefore, during DFS from the ocean, we only move to neighbours whose height is greater than or equal to the current cell.

        if (heights[nRow][nCol] >= heights[row][col])
        */
       
        if(nRow<rowSize && nCol<colSize && nRow>=0 && nCol>=0 && !visited[nRow][nCol] && heights[nRow][nCol]>=heights[row][col])
            dfs(nRow,nCol,heights,visited);


    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>&heights)
{
    rowSize = heights.size();
    colSize = heights[0].size();
     
    vector<vector<bool>>atlantic(rowSize,vector<bool>(colSize,false));
    vector<vector<bool>>pacific(rowSize,vector<bool>(colSize,false));

    for(int row=0;row<rowSize;++row)
    {
        dfs(row,0,heights,pacific);
        dfs(row,colSize-1,heights,atlantic);
    }

    for(int col=0;col<colSize;++col)
    {
        dfs(0,col,heights,pacific);
        dfs(rowSize-1,col,heights,atlantic);
    }

    vector<vector<int>>ans;
    for(int row=0;row<rowSize;++row)
    {
        for(int col=0;col<colSize;++col)
        {
            if(atlantic[row][col] && pacific[row][col])
                ans.push_back({row,col});
        }
    }
    return ans;


}




int main()
{
    vector<vector<int>>heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};

    vector<vector<int>>ans = pacificAtlantic(heights);

    for(int i=0;i<ans.size();++i)
    {
        for(int j=0;j<ans[0].size();++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;

}