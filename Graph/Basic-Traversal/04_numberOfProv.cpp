#include<iostream>
#include<vector>
#include<queue>


using namespace std;


int findCircleNum(vector<vector<int>>&isConnected)
{

    int vertices = isConnected.size();
    vector<vector<int>>adjList(vertices);
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            if(isConnected[i][j] == 1)
                adjList[i].push_back(j);
            
        }
    }

    vector<bool>visited(vertices,false);
    int count = 0;

    for(int i=0;i<vertices;++i)
    {
        if(visited[i])
            continue;
        
        queue<int>q;
        q.push(i);
        visited[i] = true;
        count++;

        while(!q.empty())
        {
            int currentNode = q.front();
            q.pop();
            for(auto neighbour:adjList[currentNode])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    return count;


}
int main()
{

    vector<vector<int>>isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout<<findCircleNum(isConnected);

    return 0;

}