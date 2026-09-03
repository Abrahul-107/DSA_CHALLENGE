#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

vector<int>nextGreaterElement(vector<int>&nums1,vector<int>&nums2)
{
    stack<int>st;
    unordered_map<int,int>greater;
    vector<int>ans;

    for(int num:nums2)
    {
        while (!st.empty() && st.top()<num)
        {
            greater[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    while(!st.empty())
    {
        greater[st.top()] = -1;
        st.pop();
    }
    for(int num:nums1)
    {
        ans.push_back(greater[num]);
    }

    return ans;
}


int main()
{

    vector<int>nums1 = {4,1,2};
    vector<int>nums2 = {1,3,4,2};

    vector<int>ans = nextGreaterElement(nums1,nums2);

    for(auto it:ans)
        cout<<it<<" ";
        


    return 0;
}