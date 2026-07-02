#include<iostream>

using namespace std;

int findSmallestDivisor(vector<int>&arr,int threshold)
{
    int maxElement = *std::max_element(arr.begin(),arr.end());
    int left = 1;
    int right = maxElement;
    int ans = INT_MAX;

    while(left<=right)
    {
        int mid = (left+right)/2;
        int divisorSum = 0;

        for(auto num:arr)
            divisorSum += ceil(double(num)/mid);
        if(divisorSum<=threshold)
        {
            ans = min(ans,mid);
            right = mid - 1;
        }
        else
            left = mid + 1;

    }
    return ans;
}

int main()
{
    vector<int>arr = {1,2,5,9};
    cout<<findSmallestDivisor(arr,6);



    return 0;
}