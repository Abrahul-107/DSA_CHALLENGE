#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



int length(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

ListNode *reverseKGroup(ListNode *head, int k)
{

    int count = 0;
    int len = length(head);

    //Edge case
    if (head == NULL || k > len)
        return head;

    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *forward = curr->next;

    //Revere first k group
    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    //Recursively do the same for rest node
    if (forward != NULL)
        head->next = reverseKGroup(forward, k);
    // return prev ,the head of reversed node
    return prev; 
}
int main()
{
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2; // Reverse every k nodes

    ListNode *reversedHead = reverseKGroup(head, k);

    cout << "Reversed list in groups of " << k << ": ";
    while (reversedHead)        
    {
        cout<<reversedHead->val<<" ";
        reversedHead = reversedHead->next;
    }
    

    // Clean up allocated memory
    while (reversedHead != nullptr)
    {
        ListNode *nextNode = reversedHead->next;
        delete reversedHead;
        reversedHead = nextNode;
    }

    return 0;
}