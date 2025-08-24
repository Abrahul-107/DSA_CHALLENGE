#include<iostream>
using namespace std;

class LinkedList
{
public:
    int data;
    LinkedList *next;

    LinkedList(int val):data(val),next(nullptr){}
    ~LinkedList()
    {
        delete next;
    }

};

void TraverseList(LinkedList *head)
{
    cout<<"------------------------------";
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

LinkedList *reverseIteratively(LinkedList*head)
{
    if(head==nullptr || head->next==nullptr)
        return head;
    LinkedList *forwardPointer = nullptr;
    LinkedList *currentPointer = head;
    LinkedList *previousPointer = nullptr;

    while(currentPointer)
    {
        forwardPointer = currentPointer->next;
        currentPointer->next = previousPointer;
        previousPointer = currentPointer;
        currentPointer = forwardPointer;
    }
    return previousPointer;
}
LinkedList * reverseList(LinkedList*head)
{
    if(head==nullptr || head->next ==nullptr)
        return head;
    LinkedList *newNode = reverseList(head->next);
    head->next->next = head;
    cout<<head->next->next->data<<" ";
    head->next = nullptr;
    return newNode;
}

int main()
{
    LinkedList* list = new LinkedList(2);
    list->next = new LinkedList(3);
    list->next->next = new LinkedList(4);
    list->next->next->next = new LinkedList(5);
    list->next->next->next->next = new LinkedList(6);

    TraverseList(list);
    LinkedList *newNode = reverseIteratively(list);
    TraverseList(newNode);




    return 0;

}