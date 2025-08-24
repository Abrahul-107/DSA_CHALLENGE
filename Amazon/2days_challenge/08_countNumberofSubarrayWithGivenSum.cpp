#include<iostream>
using namespace std;


int countNumberOfSubarrayWithGivenSum(vector<int>&arr,int target)
{
    int prefixSum = 0,count=0;
    unordered_map<int,int>prefixCount;
    prefixCount[0]= 1;

    for(int num:arr)
    {
        prefixSum += num;
        if(prefixCount.find(prefixSum-target) != prefixCount.end())
            count += prefixCount[prefixSum-target];
        prefixCount[prefixSum]++;
    }
    return count;
}

int main()
{
    vector<int>arr = {10, 2, -2, -20, 10};
    int target = 10;
    int answer = countNumberOfSubarrayWithGivenSum(arr,target);
    cout<<answer;
    
    return 0;
}