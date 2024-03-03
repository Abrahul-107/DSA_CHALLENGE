#include<bits/stdc++.h>
using namespace std;

// Declaration of STACK
class Stack 
{
    int maxSize; // Renamed from size
    int *arr;
    int topIndex; // Renamed from top

public:
    Stack() 
    {
        topIndex = -1;
        maxSize = 1000;
        arr = new int[maxSize];
    }

    void push(int x) 
    {
        // Just increment the top and assign the value to the topIndex
        topIndex++;
        arr[topIndex] = x;
    }

    int pop() 
    {
        // Just decrement the topIndex
        int x = arr[topIndex];
        topIndex--;
        return x;
    }

    int peek() 
    { 
        // Renamed from top
        return arr[topIndex];
    }

    int getSize() 
    { 
        // Renamed from size
        return topIndex + 1;
    }
    void display()
    {
        //Display the stack 
        for(int i=getSize()-1;i>=0;i--)
        {
            cout<<arr[i]<<endl;
        }
    }
};

int main() {
    Stack st;
    st.push(6);
    st.push(8);
    st.push(4);
    st.push(11);
    st.push(56);

    cout << "Size is " << st.getSize() << endl;
    cout << "Top is " << st.peek() << endl;
    st.pop();
    cout << "After popping out, top is " << st.peek() << endl;
    st.display();
    

    return 0;
}
