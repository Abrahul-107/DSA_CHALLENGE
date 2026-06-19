#include<iostream>
using namespace std;


class Node
{
public:
    int data;
    Node* next;
    Node(){data=0,next=nullptr;};
    Node(int val){data=val,next=nullptr;};

};

void displayLinkedList(Node *head)
{
    while (head)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    // cout<<"nullptr";
    
}

void displayRecusrively(Node *head)
{
    if(head==nullptr || head->next==nullptr)
        return;
    cout<<head->data<<"->";
    displayLinkedList(head->next);
}

int main()
{
    Node* head = new Node(5);
    head->next = new Node(6);
    head->next->next = new Node(7);
    head->next->next->next = new Node(10);

    // displayLinkedList(head);
    displayRecusrively(head);
    return 0;
    

}