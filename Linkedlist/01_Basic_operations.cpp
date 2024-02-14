#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    // Constructor for Node
    Node(const T &data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    // Initialize the head with nullptr
    LinkedList() : head(nullptr) {}

    // For push operation
    void push(const T &data)
    {
        Node<T> *newnode = new Node<T>(data);
        if (!head)
            head = newnode;
        else
        {
            Node<T> *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newnode;
        }
    }


    // For display the linked list
    void display()
    {
        Node<T> *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    //Delete the node from tail
    void deleteTailNode()
    {
        if (!head) {
            cout << "Cannot delete tail node because the linked list is empty" << endl;
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* temp = head;
        Node<T>* prev = nullptr;

        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }

        delete temp;
        prev->next = nullptr;
        cout<<"Successfully deleted "<<endl;
        
    }
    
    // Clear method deletes all nodes in the list and frees memory
    void clear()
    {
        while (head)
        {
            // Store the current head in a temporary pointer
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

};

int main()
{
    LinkedList<int> ll;
    ll.push(5);
    ll.push(7);
    ll.push(9);

    // ll.display();
    // ll.length();
    ll.deleteTailNode();
    ll.display();

    return 0;
}
