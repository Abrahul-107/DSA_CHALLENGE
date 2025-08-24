#include<iostream>
using namespace std;

vector<int> subarrayWithGivenSum(vector<int>&arr,int target)
{
    int firstPointer = 0;
    int prefixSum = 0;
    for(int secondPointer=0;secondPointer<arr.size();++secondPointer)
    {
        prefixSum = prefixSum + arr[secondPointer];
        while(prefixSum>target && firstPointer<=secondPointer)
        {
            prefixSum -= arr[firstPointer];
            firstPointer++;
        }
        if(prefixSum==target)
            return {firstPointer+1,secondPointer+1};
    }
    return {-1};
}

int main()
{
    vector<int>arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int target = 23;
    vector<int>ans = subarrayWithGivenSum(arr,target);
    for(auto ansElement:ans)
        cout<<ansElement<<" ";

    return 0;

}