//https://leetcode.com/problems/rotting-oranges/description/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int orangeRotting(vector<vector<int>>&grid)
{
    int rowSize = grid.size();
    int colSize = grid[0].size();

    queue<pair<pair<int,int>,int>>q;


    int visited[rowSize][colSize];
    for(int i=0;i<rowSize;i++)
    {
        for(int j=0;j<colSize;++j)
        {
            if(grid[i][j] == 2)
            {
                visited[i][j] = 2;
                q.push({{i,j},0});
            }
            else
                visited[i][j] = 0;

        }
    }

    int maxTime = 0;
    /*
    2 1 1
    1 1 0
    0 1 1
    
    */
    vector<int>delRow = {0,0,1,-1};
    vector<int>delCol = {-1,1,0,0};
    
    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        maxTime = max(t,maxTime);
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow>=0 && nCol>=0 && nRow<rowSize && nCol<colSize && grid[nRow][nCol]==1 && visited[nRow][nCol]==0)
            {
                q.push({{nRow,nCol},t+1});
                visited[nRow][nCol] = 2;
            }
        }

    }

    for(int i=0;i<rowSize;++i)
    {
        for(int j=0;j<colSize;++j)
        {
            if(visited[i][j] == 0 && grid[i][j] ==1)
                return -1;
        }
    }
    return maxTime;
}


int main()
{
    vector<vector<int>>grid = {{2,1,1},{0,1,0},{0,1,1}};
    cout<<orangeRotting(grid);
    

    return 0;
}