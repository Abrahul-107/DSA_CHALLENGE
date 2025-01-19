#include<bits/stdc++.h>
using namespace std;

/*
STL Functions for Heap Operations
    make_heap(): Converts given range to a heap.
    push_heap(): Arrange the heap after insertion at the end.
    pop_heap(): Moves the max element at the end for deletion.
    sort_heap(): Sort the elements of the max_heap to ascending order.
    is_heap(): Checks if the given range is max_heap.
    is_heap_until(): Returns the largest sub-range that is max_heap.
All of the above functions are defined inside the <algorithm> header file.
*/

void makeHeap(vector<int>arr)
{
    //Converting vector into heap using make_heap() function
    make_heap(arr.begin(),arr.end());
    //This should return the maximum element in the vector
    cout<<arr.front();
}


int main()
{
    vector<int>arr = {20,12,34,56,10,134};
    makeHeap(arr);

    return 0;


}