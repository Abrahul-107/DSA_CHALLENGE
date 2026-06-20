//https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>firstNegInt(vector<int>&arr,int k)
{
    int firstPointer=0,secondPointer=0;
    int size = arr.size();

    //Have to take queue data structure because we have to remove the front frequently
    queue<int>negativeQ;
    vector<int>ans;

    while(secondPointer<size)
    {
        //calculation for window
        if(arr[secondPointer]<0)
            negativeQ.push(arr[secondPointer]);

        //Putting ans in window
        if(secondPointer-firstPointer+1 == k)
        {
            //if we are not getting any negative number in this specific window thn we have to put 0 
            if(negativeQ.empty())
                ans.push_back(0);
            else{
                ans.push_back(negativeQ.front());
                if(arr[firstPointer]==negativeQ.front())
                    negativeQ.pop();
            }
            firstPointer++;

        }
        else
            secondPointer++;

    }
    return ans;

}



int main()
{
    vector<int>arr = {-8, 2, 3, -6, 10};
    vector<int>ans = firstNegInt(arr,2);
    // ans should be {-8,0,-6,-6}
    for(auto it:ans)
        cout<<it<<" ";


    return 0;
}