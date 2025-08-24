#include<iostream>
using namespace std;

vector<vector<int>>mergeInterval(vector<vector<int>>&arr)
{
    vector<vector<int>>mergedArray;
    vector<int>previousArray = arr[0];

    for(int index=1;index<arr.size();++index)
    {
        if(arr[index][0]<=previousArray[1])
            previousArray[1] = arr[index][1];
        else
        {
            mergedArray.push_back(previousArray);
            previousArray = arr[index];
        }
    }
    mergedArray.push_back(previousArray);
    return mergedArray;
}



int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 4}, {3, 5}, {6, 7}};

    vector<vector<int>>ans = mergeInterval(arr);
    /*
        output should be : [[1,5],[6,7]]
    */
    for(vector<int> arr:ans)
    {
        for(int element:arr)
            cout<<element<<" ";
        cout<<endl;

    }


    return 0;
}