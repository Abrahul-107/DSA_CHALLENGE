#include<iostream>
using namespace std;

int maxProfitFromStock(vector<int>&arr)
{
    int maximumProfit = INT_MIN;
    int minimumBuy = arr[0];
    int size = arr.size();

    for(int index = 1;index<size;++index)
    {
        minimumBuy = min(minimumBuy,arr[index]);
        int currentProfit = arr[index] - minimumBuy;
        maximumProfit = max(maximumProfit,currentProfit);
    }
    return maximumProfit;
}

int main()
{
    vector<int>arr = {7,1,5,3,6,4};
    cout<<maxProfitFromStock(arr);


    return 0;

}