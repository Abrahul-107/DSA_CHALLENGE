#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}
    Node(int value, Node *nxt) : data(value), next(nxt) {}
};

Node* middleOfLinkedList(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    Node* temp = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
    

}
int main()
{
    Node * ll = new Node(1);
    ll->next = new Node(2);
    ll->next->next = new Node(3);
    ll->next->next->next = new Node(4);
    ll->next->next->next->next = new Node(5);
    ll->next->next->next->next->next = new Node(6);
    

    Node* ans = middleOfLinkedList(ll);
    cout<<ans->data;

    return 0;

}