#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;

    Node():data(0),next(nullptr){}
    Node(int val):data(val),next(nullptr){}
    Node(int val,Node* nxt):data(val),next(nxt){}

};

/*Iterative approch For reversing the linkedlist */
Node* reverseLinkedList(Node* head)
{
    if(head == NULL || head->next == NULL) return head;
    Node *forward = nullptr;
    Node *current =  head;
    Node *previous = nullptr;

    while (current)
    {
       forward = current->next;
       current->next = previous;
       previous =  current;
       current = forward;
    }
    return previous;
}

/*Recursive approch for reverse a linkedlist */
Node* reverseLinkedListRecursive(Node* head)
{
    if(head == NULL || head->next == NULL) return head;
    Node* newNode = reverseLinkedListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newNode;
    
}


int main()
{
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);
    l1->next->next->next = new Node(6);
    l1->next->next->next->next = new Node(8);

    Node* result = reverseLinkedListRecursive(l1);

    
    while (result != nullptr) 
    {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;

}
