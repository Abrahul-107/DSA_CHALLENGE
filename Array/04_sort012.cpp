/*Dutch National flag */

#include <bits/stdc++.h>
using namespace std;

void dutchNationalFlag(vector<int> &arr)
{
    int size = arr.size();
    int forzero = 0;
    int forone = 0;
    int fortwo = size-1;

    while(forone<=fortwo)
    {
        if(arr[forone]==0)
            swap(arr[forzero++],arr[forone++]);
        else if(arr[forone]==1)
            forone++;
        else if(arr[forone]==2)
            swap(arr[forone],arr[fortwo--]);

    }
    for(auto it:arr)
        cout<<it<<" ";

}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);

    
    dutchNationalFlag(arr);

    return 0;
}