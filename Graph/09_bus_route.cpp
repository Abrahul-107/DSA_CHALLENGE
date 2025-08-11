#include<iostream>
using namespace std;


int numBusesToDestination(vector<vector<int>>&routes,int source , int target)
{
    //if target == source don't have to travel so return 0
    if(source==target)
        return 0;
    
    // Take map ds for storing the stops with corresponding indices(which contains each routes)
    unordered_map<int,vector<int>> stopToRoute;


    //Store the indices to its corresponding routes first 
    for(int route=0;route<routes.size();++route)
        for(int stop:routes[route])
            stopToRoute[stop].push_back(route);

    //Maintain queue for performing BFS for getting the target 
    queue<int>q;
    vector<bool>visited(routes.size(),false);

    //First took the source and enter the route(corresponding indices) into queue
    for(auto route:stopToRoute[source])
    {
        q.push(route);
        visited[route] = true;

    }

    //busToTaken 
    int busToTaken = 1;

    while(!q.empty())
    {
        //Size for finding the stop
       int size = q.size();
       while(size--)
       {
            int route = q.front();
            q.pop();

            //First traverse the routes[indices] for finding the target if target found thn return the busToTaken
            // Explore all stops in the current route
            for(auto stop:routes[route])
            {
                if(stop==target)
                    return busToTaken;

                // Add all new routes accessible from this stop
                for(int nextRoute:stopToRoute[stop])
                {
                    if(!visited[nextRoute])
                    {
                        visited[nextRoute] = true;
                        q.push(nextRoute);
                    }

                }
            }
       }
       //Increase the count of bus to taken
       busToTaken++;
    }
    return -1;
}

int main()
{
    vector<vector<int>> routes = {{1,2,7},{3,6,7}};
    int source = 1;
    int target = 6;
    cout<<numBusesToDestination(routes,source,target);

    return 0;
}