#include<bits/stdc++.h>
using namespace std;

class AdjecencyList
{

private:
    int vertices;
    vector<list<int>> adjecency_list;
public:
    AdjecencyList(int v)
    {
        vertices = v;
        adjecency_list.resize(v);
    }
    void addEdges(int from, int to)
    {
        adjecency_list[from].push_back(to);
        adjecency_list[to].push_back(from); //For undirected

    }
    void printList()
    {
        for(int i=0;i<vertices;++i)
        {   
            cout << "Vertex " << i << " :";
            for (auto& vertex : adjecency_list[i]) 
                cout << " -> " << vertex;
            
            cout << endl;
        }
    }

};

int main()
{
    AdjecencyList graph(4);
    graph.addEdges(0, 1);
    graph.addEdges(0, 2);
    graph.addEdges(1, 2);
    graph.addEdges(2, 3);

    cout << "Adjacency List:" << endl;
    graph.printList();


    return 0;
}