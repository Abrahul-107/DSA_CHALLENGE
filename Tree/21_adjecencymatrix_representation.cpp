#include <bits/stdc++.h>
using namespace std;

void adjecencyList(int n)
{
     // This is our adjacency list
    vector < int > tree[n];
    
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        
        // Adding an edge from u to v
        tree[u].push_back(v);
        
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < tree[i].size(); j++) {
            cout << tree[i][j] << " ";
        }
        cout << "\n";
    }
}

void adjecencyMatrix(int n)
{
     vector < vector < int >> adjMatrix(n, vector < int > (n, 0));

    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;

        // Adding an edge from u to v
        adjMatrix[u][v] = 1;
    }

    // Printing the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    int n;
    cin>>n;
    //adjecency matrix
    adjecencyMatrix(n);
    //adjecency list
    adjecencyList(n);
   
}