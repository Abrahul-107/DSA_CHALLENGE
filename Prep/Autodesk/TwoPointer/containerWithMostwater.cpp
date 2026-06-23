#include<iostream>
#include<vector>

using namespace std;

int containerWithMostWater(vector<int>&height)
{
    int left = 0;
    int right = height.size()-1;
    int maxArea = 0;
    
    while(left<right)
    {
        int breadth = right-left;
        int currentArea = breadth * min(height[left],height[right]);
        maxArea = max(maxArea,currentArea);
        if(height[left]<height[right])
            left++;
        else
            right--;
    }
    return maxArea;
}

int main()
{
    vector<int>height = {1,8,6,2,5,4,8,3,7};
    cout<<containerWithMostWater(height);

    return 0;

}