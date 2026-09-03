//https://leetcode.com/problems/daily-temperatures/description/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int>dailyTemperatures(vector<int>&temperatures)
{
    stack<int>st;
    vector<int>ans(temperatures.size());

    for(int i=0;i<temperatures.size();++i)
    {
        while(!st.empty() && temperatures[st.top()]<temperatures[i])
        {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return ans;
}



int main()
{
    vector<int>temperatures = {73,74,75,71,69,72,76,73};

    vector<int>ans = dailyTemperatures(temperatures);

    for(auto it:ans)
        cout<<it<<" ";



    return 0;
}