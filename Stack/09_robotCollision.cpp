//https://leetcode.com/problems/robot-collisions/description/
#include<bits/stdc++.h>
using namespace std;

vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& health, string directions)
{
    int n = pos.size();

    //Actual index of the robot 
    vector<int>actualIdx(n),res;
    iota(begin(actualIdx),end(actualIdx),0);

    //Lambda for sorting the actual indexes according to the position given
    auto lambda = [&](int &left,int &right)
    {
        return pos[left]<pos[right];
    };
    sort(begin(actualIdx),end(actualIdx),lambda);

    //Stack for performing simulation 
    stack<int>st;

    for(auto &currIdx:actualIdx)
    {
        if(directions[currIdx]=='R')
            st.push(currIdx);
        else
        {
            while(!st.empty() && health[currIdx]>0)
            {
                int topIdx = st.top();
                st.pop();

                if(health[currIdx]>health[topIdx])
                {
                    health[currIdx] -=1;
                    health[topIdx]= 0;
                }
                else if(health[currIdx]<health[topIdx])
                {
                    health[topIdx]-=1;
                    health[currIdx] = 0;
                }
                else
                {
                    health[topIdx] = 0;
                    health[currIdx] = 0;
                }
            }
        }
    }
    for(auto it:health)
    {
        if(it>0)
            res.push_back(it);
    }
    return res;
}
int main()
{
    vector<int>positions = {3,5,2,6};
    vector<int> healths = {10,10,15,12}; 
    string directions = "RLRL";

    vector<int>ans = survivedRobotsHealths(positions,healths,directions);
    for(auto it:ans)
        cout<<it<<" ";

    return 0;
}