#include<iostream>
#include<vector>

using namespace std;


void dfs(int node,vector<vector<int>>&Graph,vector<bool>&visited)
{
    visited[node] = true;
    cout<<node<<" ";

    for(int neighbour:Graph[node])
    {
        if(!visited[neighbour])
            dfs(neighbour,Graph,visited);

    }

}


int main()
{
    int n = 4;
    vector<vector<int>> Graph = {
        {1, 2}, // 0
        {0, 3}, // 1
        {0},    // 2
        {1}     // 3
    };
    vector<bool>visited(n,false);
    dfs(0,Graph,visited);

    return 0;
}