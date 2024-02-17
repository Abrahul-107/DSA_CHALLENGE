#include <bits/stdc++.h>
using namespace std;

// Struct for linkedlist
struct Node
{
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node *nxt) : data(val), next(nxt) {}
};

// function for finding the loop
bool detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        // If loop detected , so we hv to return True
        if (slow == fast)
            return true;
    }

    // Else return false
    return false;
}

// Main function
int main()
{
    Node *list = new Node(2);
    list->next = new Node(6);
    list->next->next = new Node(7);
    list->next->next->next = list->next;

    if (detectLoop(list))
        cout << "Has a loop";
    else
        cout << "No loop ";

    return 0;
}