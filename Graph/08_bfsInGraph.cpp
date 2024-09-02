#include<bits/stdc++.h>
using namespace std;

class AdjecencyList
{

public:
    int vertices;
    vector<list<int>>adjList;

public:
    AdjecencyList(int v)
    {
        vertices = v;
        adjList.resize(v);
    }
    void addEdge(int from,int to)
    {
        adjList[from].push_back(to);//Directed graph
    }
    void printList()
    {
        for(int i=0;i<adjList.size();i++)
        {
            cout<<"Vertex :"<<i<<" ";
            for(auto j:adjList[i])
            {
                cout<<"->"<<j;
            }
            cout<<endl;
        }
    }

};


vector<int>bfsInGraph(int v,vector<list<int>>adj)
{
    int visited[v]= {0}; // Visited array of v size
    visited[0] = 1; //For 0 push 1 which marking as it already visited
    queue<int>q; //Declaration of queue for BFS
    q.push(0);  //Push of 0 because it already visited


    //for returning the bfs of the graph
    vector<int>bfs;


    while(!q.empty())
    {
        //Storing and poping out the node so that we can visit of that nodes breadth
        int node = q.front();
        q.pop();
        
        bfs.push_back(node);

        //Bfs with help of visited array
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;

}



int main()
{
    AdjecencyList graph(4);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(3,0);

    graph.printList();
    vector<int> bfsResult = bfsInGraph(4,graph.adjList);
    cout << "BFS Traversal: ";
    for (int i : bfsResult)
        cout << i << " ";
    cout << endl;



    return 0;
}