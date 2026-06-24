#include<iostream>

using namespace std;

class MyStack
{
private:
    int size;
    int top;
    int *arr;

public:
    MyStack(int size)
    {
        this->size = size;
        this->top = -1;
        arr = new int[size];
    }
    void push(int element)
    {
        if(top==size-1)
            cout<<"StackOverflow"<<endl;
        arr[++top] = element;
    }
    void pop()
    {
        if(top==-1)
            cout<<"StackUnderflow"<<endl;
        top--;
    }
    int peek()
    {
        if(top==-1)
            cout<<"StackUnderflow"<<endl;
        return arr[top];
    }
    void displayStack()
    {
        if(top==-1)
            cout<<"No elements are there"<<endl;
        else
            for(int i=top;i>=0;i--)
                cout<<arr[i]<<" ";

    }

};


int main()
{
    MyStack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.pop();
    stack.displayStack();



    return 0;
}