#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>&arr)
{
    int curr_count = 0;
    int max_count = 0;

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==1)
            curr_count++;
        else
            curr_count = 0;
        max_count = max(curr_count,max_count);
    }
    return max_count;

}


int main()
{
    vector<int> arr = {1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1};
    cout << findMaxConsecutiveOnes(arr) << '\n';
    return 0;
}