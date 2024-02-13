#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr)
{
    int size = arr.size();
    sort(arr.begin(), arr.end());

    int count = 1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] == arr[i - 1])
            count++;
        else
        {
            if (count > size / 3)
                return arr[i - 1];
            count = 1;
        }
    }
    if (count > size / 3)
        return arr[size - 1];
    return -1;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(1);

    
    cout<<majorityElement(arr);

    return 0;
}