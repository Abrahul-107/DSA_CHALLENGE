#include<iostream>
using namespace std;


vector<int>subarrayWithGivenSumNegativeIncluded(vector<int>&arr,int target)
{
    unordered_map<int,int>prefixIndex;
    int prefixSum = 0;
    for(int index=0;index<arr.size();++index)
    {
        prefixSum += arr[index];
        
        //First case : If the prefixSum match the target thn we have to return with indexing 1
        if(prefixSum == target)
            return {1,index};
        
        //Second case: If the target - prefixSum in the prefix index thn return from there
        if(prefixIndex.find(prefixSum-target) != prefixIndex.end())
        {
            int start = prefixIndex[prefixSum-target] +2 ; //Because of 0 indexing
            int end = index ;
            return {start,end};
        }

        // Third case if none of the above case thn we have to store the prefix sum in the prefix index map
        prefixIndex[prefixSum] = index;
    }
    return {-1,-1};
}

int main()
{
    vector<int>arr = {10, 2, -2, -20, 10};
    int target = -10;
    vector<int>answer = subarrayWithGivenSumNegativeIncluded(arr,target);

    for(int element:answer)
        cout<<element<<" ";

    return 0;
}