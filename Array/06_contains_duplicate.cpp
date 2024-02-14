/*Time complexity = 0(N)
  Space complexity = 0(1)*/
  
#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(int *arr,int n) {
        
        unordered_map<int,int>dupli;
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(dupli[arr[i]]>=1)
            return true;

            dupli[arr[i]]++;

        }
        return false;
    }


int main()
{
    int arr[] = {1,2,3,2,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<containsDuplicate(arr,6);


}