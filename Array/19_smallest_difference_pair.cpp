#include<bits/stdc++.h>
using namespace std;

//Time complexity = O(NlogN) + O(MlogM)

int findSmallestDifference(int *a,int *b,int m,int n)
{
    int i=0,j=0;
    sort(a,a+m);
    sort(b,b+n);

    int minimum_value = INT_MAX;

    while(i<m && j<n)
    { 
        minimum_value = min(minimum_value,(a[i]-b[j]));
        if(a[i]<b[j])
            i++;
        else
            j++;
    }
    return minimum_value;

}
int main()
{    
    int A[] = {1, 2, 11, 5};
    int B[] = {4, 12, 19, 23, 127, 235};


    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    cout << findSmallestDifference(A, B, m, n);

    return 0;
}