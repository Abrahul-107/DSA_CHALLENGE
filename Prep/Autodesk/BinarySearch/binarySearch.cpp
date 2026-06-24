#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>&arr,int target)
{
    int start = 0 ;
    int end = arr.size() - 1;

    while(start<=end)
    {
        int mid = (start + end)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]<target)
            start = mid + 1;
        else 
            end = mid - 1;

    }
    return -1;


}

int main()
{
    vector<int>arr = {-1,0,3,5,9,12};
    int target = 9;

    cout<<binarySearch(arr,target);


    return 0;


}