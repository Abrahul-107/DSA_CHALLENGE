#include<bits/stdc++.h>
using namespace std;
#define maxx 100

void heapify(int *arr,int i,int n)
{
    int parent = (i-1)/2;

    if(parent>=0)
    {
        if(arr[i]>arr[parent])
        {
            swap(arr[i],arr[parent]);
            heapify(arr,parent,n);

        }
        
    }

}

void insert(int *arr,int &n,int key)
{
    n = n+1;
    arr[n-1] = key;

    heapify(arr,n-1,n);

}
void printHeap(int *arr,int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

}
int main()
{
    int arr[maxx] = { 10, 5, 3, 2, 4 };
    int n = 5;

    int key = 15;
    insert(arr,n,key);
    cout<<"After inserting the heap is "<<endl;
    printHeap(arr,n);



    return 0;
}
