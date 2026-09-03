#include <bits/stdc++.h>
using namespace std;

class GraphMatrix
{
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    GraphMatrix(int v)
    {
        vertices = v;
        adjMatrix.assign(v, vector<int>(vertices, 0));
    }

    void addEdges(int from, int to)
    {
        adjMatrix[from][to] = 1;
        adjMatrix[to][from] = 1; // Since it's an undirected graph
    }


    //union find algo technique
    int find(int x, vector<int> &parent)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x], parent);
    }

    int numberOfConnectedComponent()
    {
        vector<int> parent(vertices);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (adjMatrix[i][j])
                {
                    parent[find(i, parent)] = parent[find(j, parent)];
                }
            }
        }

        int components = 0;
        for (int i = 0; i < vertices; i++)
        {
            if (parent[i] == i)
                components++;
        }
        return components;
    }
};

int main()
{
    GraphMatrix graph(5);
    graph.addEdges(0, 1);
    graph.addEdges(1, 2);
    graph.addEdges(3, 4);
    cout << "Total number of components are " << graph.numberOfConnectedComponent() << endl;
    return 0;
}
