#include<iostream>
#include<vector>

using namespace std;

int countOnes(vector<int>&arr)
{
    int count = 0;
    for(int it:arr)
    {
        if(it==1)
            count++;
    }
    return count;
}

int minSwap(vector<int>&arr)
{
    int totalOneCount = countOnes(arr);

    if(totalOneCount ==0) return -1;
    if (totalOneCount == 1) return 0;


    int i = 0, j = 0;
    int n = arr.size();
    int maxOneWindow = 0;
    int oneCount = 0;

    while(j<n)
    {
        // if(arr[j]==1) it can also work
        //     oneCount ++;
        oneCount += arr[j];
        
        if(j-i+1 > totalOneCount)
        {
            oneCount -= arr[i];
            i++;

        }
        maxOneWindow = max(oneCount,maxOneWindow);
        j++;

    }
    return totalOneCount - maxOneWindow;
}


int main()
{
    vector<int>arr = {1, 0, 1, 0, 1, 1};
    cout<<minSwap(arr);

    return  0;
}