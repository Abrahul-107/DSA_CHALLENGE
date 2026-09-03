#include<iostream>
#include<vector>

using namespace std;

int findCheapestPrice(int n,vector<vector<int>>&flights,int src,int dst,int k)
{
    vector<int>minPrice(n,1e9);
    minPrice[src] = 0;

    for(int stop=0;stop<=k;++stop)
    {
        vector<int>currentPrice = minPrice;
        for(auto flight:flights)
        {
            int source = flight[0];
            int dest = flight[1];
            int price = flight[2];

            if(minPrice[source]==1e9)
                continue;
            currentPrice[dest] = min(currentPrice[dest],minPrice[source]+price);

        }
        minPrice = currentPrice;
    }
    if(minPrice[dst]!=1e9)
        return minPrice[dst];
    else
        return -1;
}

int main() 
{
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