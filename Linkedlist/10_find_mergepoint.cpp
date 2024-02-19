#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node *nxt) : data(val), next(nxt) {}
};
int length(Node *temp)
{
    int c = 0;
    while (temp)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
Node *findMergePoint(Node *heada, Node *headb)
{
    int lenfirst = length(heada);
    int lensecond = length(headb);

    Node *first = heada;
    Node *second = headb;

    while (lenfirst > lensecond)
    {
        first = first->next;
        lenfirst--;
    }
    while (lensecond > lenfirst)
    {
        second = second->next;
        lensecond--;
    }

     while (first != second) {
        first = first->next;
        second = second->next;
    }
    return first;
    return nullptr;
}
int main()
{
    Node *list = new Node(8);
    list->next = new Node(9);
    list->next->next = new Node(10);
    list->next->next->next = new Node(5);
    list->next->next->next->next = new Node(1);

    Node *list2 = new Node(1);
    list2->next = list->next->next;

    Node *ans = findMergePoint(list, list2);
    cout<<ans->data<<" ";

    return 0;
}