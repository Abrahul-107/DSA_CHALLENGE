#include<iostream>
#include<vector>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node(int val){data=val,next=nullptr;}


};

int middleOfTheList(Node *head)
{
    Node *fastPtr = head;
    Node *SlowPtr = head;

    Node *current = head;
    while(fastPtr && fastPtr->next)
    {
        SlowPtr = SlowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return SlowPtr->data;

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
    cout<<middleOfTheList(head)<<endl;

    return 0;



}