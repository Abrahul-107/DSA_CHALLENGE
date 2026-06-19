#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value){data=value,next=nullptr;}

};

void displayLinkedList(Node *head)
{
    while (head)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"nullptr"<<endl;
}

void searchInList(Node *head,int searchItem)
{
    int c = 0;
    Node *dummy = head;

    while(dummy)
    {
        if(dummy->data == searchItem)
            cout<<"SearchItem is in position :"<<c;
        dummy = dummy->next;
        c++;
        
    }


}
int lengthOfList(Node *head)
{
    int len = 0;
    Node *dummy = head;
    while(dummy)
    {
        len++;
        dummy = dummy->next;
    }
    return len;
}
void nthNodeFromEnd(Node *head,int n)
{

    int length = lengthOfList(head);
    cout<<"Lenght of the list is "<< length<<endl;
    int haveToReach = length - n;
    Node *dummy = head;
    while(haveToReach--)
        dummy = dummy->next;

    cout<<n<<" Node from End is "<<dummy->data;



}
int main()
{

   vector<int>arr = {2,4,5,6,7,8,9,10,11};
   Node *head = new Node(1);
   Node *dummy = head;
   for(auto it:arr)
   {
        dummy->next = new Node(it);
        dummy = dummy->next;
   }
   displayLinkedList(head);
   nthNodeFromEnd(head,2);
   displayLinkedList(head);
   searchInList(head,2);
   displayLinkedList(head);
        
   
    

    return 0;
}