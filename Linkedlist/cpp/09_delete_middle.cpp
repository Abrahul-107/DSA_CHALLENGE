#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int val):data(val),next(nullptr){}
    Node(int val,Node* nxt):data(val),next(nxt){}
};

Node* deleteMiddle(Node* head)
{
    Node *fast = head;
    Node *slow = head;
    Node *prev = nullptr;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
    

}
int main()
{
    Node *list = new Node(8);
    list->next = new Node(9);
    list->next->next = new Node(10);
    list->next->next->next = new Node(5);
    list->next->next->next->next = new Node(1);

    Node* ans = deleteMiddle(list);
    while (ans)
    {
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    return 0;

}