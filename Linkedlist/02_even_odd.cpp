#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node
{
public:
    T data;
    Node* next;

    //Constructor for class Node
    Node(const T &data): data(data),next(nullptr){}

};

template<typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    //Constructor for Linkedlist
    LinkedList(): head(nullptr){}

    //For finding the length of Linkedlist
    void length()
    {
        Node<T>* temp = head;
        int c = 0;
        
        while (temp)
        {
            c++;
            temp = temp->next;
        }
        cout<<"The length is "<<c<<endl;
        
    }
    //Count of positive and negative element in linkedlist
    void positiveNegative()
    {
        int even = 0 ,odd = 0;
        Node<T> * temp = head;
        while (temp)
        {
            
            if(temp->data %2==0)
                even++;
            else
                odd++;
            temp = temp->next;
        }
        cout<<"The number of positive element in linkedlist "<<even<<endl;
        cout<<"The number of negative element in linkedlist "<<odd<<endl;
        

    }
    void push(const T &data)
    {
        Node<T>*newnode = new Node<T>(data);

        if (!head)
            head = newnode;
        else
        {
            Node<T>*temp =  head;
            while(temp->next)
            temp = temp->next;
            temp->next = newnode;
        }
    }

    void display()
    {
        Node<T>*temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};




int main()
{
    LinkedList<int>ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(6);
    ll.push(7);
    

    ll.display();
    ll.length();
    ll.positiveNegative();


    return 0;

}