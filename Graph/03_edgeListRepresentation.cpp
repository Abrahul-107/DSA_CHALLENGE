#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class GraphEdgeList
{
private:
    int vertices;
    vector<pair<int, int>> edges;

public:
    GraphEdgeList(int V)
    {
        vertices = V;
    }

    void addEdge(int from, int to)
    {
        edges.push_back(make_pair(from, to));
        // edges.push_back(make_pair(to, from)); // For undirected graph
    }

    void printEdgeList()
    {
        cout << "Edge List:" << endl;
        for (auto &edge : edges)
        {
            cout << edge.first << " -> " << edge.second << endl;
        }
    }
};

int main()
{
    GraphEdgeList graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    graph.printEdgeList();

    return 0;
}
