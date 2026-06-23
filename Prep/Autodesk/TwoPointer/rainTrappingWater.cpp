#include<iostream>
using namespace std;

int maxRainTrappingWater(vector<int>&arr)
{
    int size = arr.size();
    vector<int>leftMax(size,0);
    vector<int>rightMax(size,0);
    int leftMaxHeight = 0;
    int rightMaxHeight = 0;

    for(int i=0;i<size;++i)
    {
        leftMaxHeight = max(leftMaxHeight,arr[i]);
        leftMax[i] = leftMaxHeight;
    }
    for(int i=size-1;i>=0;--i)
    {
        rightMaxHeight = max(rightMaxHeight,arr[i]);
        rightMax[i] = rightMaxHeight;
    }
    int ans = 0;
    for(int i=0;i<size;++i)
        ans += min(leftMax[i],rightMax[i]) - arr[i];
    return ans;
}

int main()
{
    vector<int>arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<maxRainTrappingWater(arr);

    return 0;

}