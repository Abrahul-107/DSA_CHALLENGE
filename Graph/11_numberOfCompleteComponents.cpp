//https://leetcode.com/problems/count-the-number-of-complete-components/description
#include<iostream>
#include<stack>

using namespace std;

int countCompleteComponents(int n,vector<vector<int>>&edges)
{
    vector<vector<int>>adjList(n);

    for(auto &e:edges)
    {
        adjList[e[0]].push_back(e[1]);
        adjList[e[1]].push_back(e[0]);
    }

    vector<bool>visited(n,false);
    int ans = 0;

    for(int i=0;i<n;i++)
    {
        stack<int>st;
        st.push(i);
        visited[i] = true;

        int nodeCount = 0;
        int degreeSum = 0;


        while (!st.empty())
        {
            int u = st.top();
            st.pop();

            nodeCount++;
            degreeSum += adjList[u].size();

            for(int neigh:adjList[u])
            {
                if(!visited[neigh])
                {
                    visited[neigh] = true;
                    st.push(neigh);
                }
            }
        }
        if(degreeSum == nodeCount*(nodeCount-1))
            ans ++;

    }
    return ans;
}





int main()
{
    int n = 6;
    vector<vector<int>>edges = {{0,1},{0,2},{1,2},{3,4}};
    cout<<countCompleteComponents(n,edges);

    return 0;

}