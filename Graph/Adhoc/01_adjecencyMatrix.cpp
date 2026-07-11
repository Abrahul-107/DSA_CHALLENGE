#include<bits/stdc++.h>
using namespace std;

class GraphMatrix
{

private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    GraphMatrix(int V)
    {
        vertices = V;
        adjMatrix.assign(vertices,vector<int>(vertices,0));
    }
    void addEdges(int from,int to)
    {
        adjMatrix[from][to] = 1;
        adjMatrix[to][from] = 1; //For undirected graph
    }
    void printMatrix()
    {
        for(int i=0;i<vertices;i++)
        {
            for(int j=0;j<vertices;j++)
            {
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<"\n";
        }

    }

};


int main()
{
    GraphMatrix graph(3);
    graph.addEdges(0, 1);
    graph.addEdges(0, 2);
    graph.addEdges(1, 2);
    graph.addEdges(2, 0);
    graph.printMatrix();

    return 0;


}