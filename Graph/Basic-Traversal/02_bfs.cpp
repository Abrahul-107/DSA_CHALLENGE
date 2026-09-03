#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<vector<int>>adj,int n)
{
    queue<int>q;
    vector<int>visited(n,0);

    for(int i=0;i<n;i++)
    {
        if(visited[i])
            continue;
            
        q.push(i);
        visited[i] = true;

        while (!q.empty())
        {
            int currentNode = q.front();
            cout<<currentNode<<" ";
            q.pop();

            for(int neighbour:adj[currentNode])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        cout<<endl;
        
    }
}




int main()
{
    vector<vector<int>> adj = {
        {1, 2}, // 0
        {0, 3}, // 1
        {0},    // 2
        {1}     // 3
    };
    bfs(adj,4);


    return 0;
}