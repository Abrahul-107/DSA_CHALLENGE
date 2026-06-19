#include<iostream>
#include<vector>
using namespace std;

class LinkedList
{
public:
    int data;
    LinkedList *next;
    LinkedList(int val){data=val,next=nullptr;}


};

void displayLinkedList(LinkedList *head)
{
    while (head)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"nullptr"<<endl;
}

/*
1 2 3 4 5
5 4 3 2 1


*/

LinkedList *reverseList(LinkedList *head)
{
    LinkedList *prev  = nullptr;
    LinkedList *current = head;
    LinkedList *forward = nullptr;

    while(current)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;

    }
    return prev;


}


int main()
{
    vector<int>arr = {2,4,5,6,7,8,9,10,11};
    LinkedList *head = new LinkedList(1);
    LinkedList *dummy = head;
    for(auto it:arr)
    {
            dummy->next = new LinkedList(it);
            dummy = dummy->next;
    }

    displayLinkedList(head);
    head = reverseList(head);
    cout<<"After reversing the list"<<endl;
    displayLinkedList(head);

    return 0;


}