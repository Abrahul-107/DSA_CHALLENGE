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

// function for finding the starting point of loop
Node *startingOfLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        // If loop detected
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }

    return nullptr;
}

// Main function
int main()
{
    Node *list = new Node(2);
    list->next = new Node(6);
    list->next->next = new Node(7);
    list->next->next->next = list->next;

    Node *ans = startingOfLoop(list);
    cout << "The loop is started from " << ans->data << endl;

    return 0;
}