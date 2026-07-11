#include <iostream>
#include <vector>
using namespace std;

int findCheapestPrice(int n,vector<vector<int>>&flights,int src,int dest,int k)
{
    vector<int>minCost(n,1e9);
    minCost[src] = 0;

    for(int stop=0;stop<=k;++stop)
    {
        vector<int>currentCost=minCost;
        for(auto flight:flights)
        {
            int source = flight[0];
            int destination = flight[1];
            int price = flight[2];


            if(currentCost[source]==1e9)
                continue;
            currentCost[destination] = min(currentCost[destination],minCost[source]+price);
            
        }
        minCost = currentCost;
    }
    if (minCost[dest]!=1e9) return minCost[dest];
    return -1;

}

int main() {
    int n = 4;

    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600}
    };

    int src = 0;
    int dst = 3;
    int k = 1;
    cout << findCheapestPrice(n, flights, src, dst, k);

    return 0;
}