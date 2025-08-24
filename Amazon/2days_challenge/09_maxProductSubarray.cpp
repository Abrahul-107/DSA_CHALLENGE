#include<iostream>
using namespace std;


int maximumProdSubarry(vector<int>&arr)
{
    int currentMaximum = arr[0],currentMinimum = arr[0], maximum = arr[0];

    for(int index=1;index<arr.size();++index)
    {
        currentMaximum = max(currentMaximum*arr[index],currentMaximum);
        currentMinimum = min(currentMinimum*arr[index],currentMinimum);
        maximum = max(maximum,currentMaximum);
    }
    return maximum;

}
vector<int> maximumProdSubarryIndex(vector<int>&arr)
{
    int currMax = arr[0],currMin = arr[0], maximum = arr[0];
    int start = 0, tempStart = 0, end = 0;
    int currentProductMax = 1,currentProductMin=1;


    for(int index=1;index<arr.size();++index)
    {
        if(arr[index]<0)
            swap(currMax,currMin);
        
        currentProductMax = arr[index]*currMax;
        currentProductMin = arr[index]*currMin;
        if(arr[index]> currentProductMax)
        {
            currMax = arr[index];
            tempStart = index;
        }
        else
        {
            currMax = currentProductMax;
        }

        currMin = min(arr[index],currentProductMin);


        if(maximum<currMax)
        {
            maximum = currMax;
            start = tempStart;
            end = index;
        }
    }
    return {start,end};

}
int main()
{
    vector<int>arr = {2,3,-2,4};
    vector<int>indexes = maximumProdSubarryIndex(arr);
    // cout<<maximumProdSubarry(arr);
    for(int ans:indexes)
        cout<<ans<<" ";


    return 0;
}