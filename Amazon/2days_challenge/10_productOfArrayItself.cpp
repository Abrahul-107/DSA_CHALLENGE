#include<iostream>
using namespace std;

vector<int> productOfArrayItself(vector<int>&arr)
{
    int zeroCount = 0;
    int index = -1;
    int prod = 1;

    for(int ind=0;ind<arr.size();++ind)
    {
        if(arr[ind]==0)
        {
            zeroCount++;
            index = ind;
        }
        else
        {
            prod *= arr[ind];
        }
    }
    vector<int>result(arr.size(),0);
    if(zeroCount==0)
    {
        for(int index=0;index<arr.size();++index)
        {
            result[index] = prod / arr[index];
        }
    }
    else if(zeroCount==1)
    {
        result[index] = prod;
    }
    return result;
}

int main()
{
    
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productOfArrayItself(arr);

    for (int val : res)
        cout << val << " ";
        
    return 0;

}