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


LinkedList* insertAtNthNode(LinkedList *head,int n,int value)
{

    LinkedList *current = head;
    for(int i=1;i<n-1;++i)
        current = current->next; 
    LinkedList *newNode = new LinkedList(value);

    newNode->next = current->next;
    current->next = newNode;

    return head;
    

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
    cout<<"After inserting the nth node"<<endl;
    head = insertAtNthNode(head,3,3);
    displayLinkedList(head);

    return 0;


}