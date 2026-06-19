#include<iostream>
#include<vector>
using namespace std;

class LinkedList
{
public:
    int data;
    LinkedList *next;

    LinkedList(int val)
    {
        data = val;
        next = nullptr;
    }
};

void displayLinkedList(LinkedList *head)
{
    while(head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

bool isPalindrome(LinkedList *head)
{
    LinkedList *slowPtr = head;
    LinkedList *fastPtr = head;

    while(fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // Skip middle node for odd length list
    if(fastPtr)
        slowPtr = slowPtr->next;

    LinkedList *prev = nullptr;
    while(slowPtr)
    {
        LinkedList *next = slowPtr->next;
        slowPtr->next = prev;
        prev = slowPtr;
        slowPtr = next;
    
    }
    LinkedList *secondHalf = prev;
    LinkedList *firstHalf = head;
    while (secondHalf)
    {
        if(firstHalf->data != secondHalf->data)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    
    }
    return true;
    
}


int main()
{
    vector<int> arr = {2, 3, 3, 2,1};

    LinkedList *head = new LinkedList(1);
    LinkedList *dummy = head;

    for(auto it : arr)
    {
        dummy->next = new LinkedList(it);
        dummy = dummy->next;
    }

    displayLinkedList(head);

    if(isPalindrome(head))
        cout << "Palindrome Linked List" << endl;
    else
        cout << "Not a Palindrome Linked List" << endl;

    return 0;
}