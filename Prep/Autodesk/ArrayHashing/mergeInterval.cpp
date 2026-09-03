#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>mergeInterval(vector<vector<int>>&intervals)
{
    sort(intervals.begin(),intervals.end());
    vector<vector<int>>ans;

    for(auto interval:intervals)
    {
        if(ans.empty() || interval[0] > ans.back()[1])
            ans.push_back(interval);
        else
            ans.back()[1] = max(ans.back()[1],interval[1]);
    }
    return ans;
}


int main()
{

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>ans = mergeInterval(intervals);

    for(int i=0;i<ans.size();++i)
    {
        for(int j=0;j<ans[0].size();++j)
            cout<<ans[i][j]<<endl;
    }        
    return 0;
}