//https://leetcode.com/problems/find-if-path-exists-in-graph/description/
#include<iostream>

using namespace std;

bool dfs(vector<vector<int>>&adjList,int node,int dest,vector<int>&visited)
{
    if(node==dest)
        return true;

    visited[node] = true;

    for(auto neighbour:adjList[node])
    {
        if(!visited[neighbour])
        {
            if(dfs(adjList,neighbour,dest,visited))
                return true;
        }
            
    }
    return false;
}

bool validPath(vector<vector<int>>&edges,int n,int src,int dest)
{
    vector<vector<int>>adjList(n);

    for(auto &edge:edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    vector<int>visited(n,0);
    return dfs(adjList,src,dest,visited);


}


int main()
{
    int n = 3;
    vector<vector<int>>edges = {{0,1},{1,2},{2,0}};
    int src = 0;
    int dest = 2;

    cout<<validPath(edges,n,src,dest);
    return 0;
}