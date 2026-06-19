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

int lenghtOfTheList(LinkedList *head)
{
    int len = 0;
    LinkedList *temp = head;

    while(temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void deleteNthNode(LinkedList *head,int n)
{
    int length = lenghtOfTheList(head);
    int step = length - n - 1;
    LinkedList *temp = head;
    while(step--)
        temp = temp->next;
    
    temp->next = temp->next->next;
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
    deleteNthNode(head,2);
    cout<<"After deleting the nth node"<<endl;
    displayLinkedList(head);

    return 0;


}