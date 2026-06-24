#include<iostream>
#include<stack>

using namespace std;

class MinStack 
{
    stack<int>st;
    stack<int>Minstack;

public:    
    
    void push(int value) 
    {
        st.push(value);
        if(Minstack.empty() || value<= Minstack.top())
            Minstack.push(value);
        
    }
    
    void pop() 
    {
        if(st.empty())
            return;

        if(st.top() == Minstack.top())
            Minstack.pop();
        st.pop();
        
    }
    
    int top() 
    {
        if(st.empty())
            return -1;
        return st.top();
        
    }
    
    int getMin() 
    {
        if(Minstack.empty())
            return -1;
        return Minstack.top();
        
    }
};


int main()
{
    MinStack ms;

    ms.push(5);
    cout << "Min: " << ms.getMin() << endl;

    ms.push(3);
    cout << "Min: " << ms.getMin() << endl;

    ms.push(7);
    cout << "Top: " << ms.top() << endl;
    cout << "Min: " << ms.getMin() << endl;

    ms.push(2);
    cout << "Min: " << ms.getMin() << endl;

    ms.pop();
    cout << "After pop:" << endl;
    cout << "Top: " << ms.top() << endl;
    cout << "Min: " << ms.getMin() << endl;

    ms.pop();
    cout << "After pop:" << endl;
    cout << "Top: " << ms.top() << endl;
    cout << "Min: " << ms.getMin() << endl;

    return 0;


}