#include<bits/stdc++.h>
using namespace std;

bool find132Pattern(int *arr, int size) {
    stack<int> st;
    int thirdelement = INT_MIN; 

    // Traverse the array from right to left
    for (int i = size - 1; i >= 0; i--) {
        // Check if the current element is less than the third element
        if (thirdelement > arr[i])
            return true; // If so, the 132 pattern is found

        // While there are elements in the stack and the current element is greater than the top element of the stack
        while (!st.empty() && arr[i] > st.top()) {
            thirdelement = st.top(); // Update the third element
            st.pop(); // Pop elements from the stack until the condition is met
        }
        
        st.push(arr[i]); // Push the current element onto the stack
    }
    return false; // If no 132 pattern is found, return false
}

int main() {
    int arr[] = {1, 2, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function and print the result
    cout << "Pattern found: " << find132Pattern(arr, n) << endl;

    return 0;
}
