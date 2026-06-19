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

LinkedList* addTwoNumbers(LinkedList *head1, LinkedList *head2)
{
    int carry = 0;
    LinkedList *dummy = new LinkedList(-1);
    LinkedList *ansList = dummy;
    while( head1 || head2 || carry != 0)
    {
        int sum = 0;
        if(head1!=nullptr)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2!=nullptr)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum / 10;
        LinkedList *newNode = new LinkedList(sum%10);
        ansList->next = newNode;
        ansList = ansList->next;
    }
    return dummy->next;
}

int main()
{
    vector<int> arr1 = {4, 3};      // Represents 342
    vector<int> arr2 = {6, 4};      // Represents 465

    LinkedList *head1 = new LinkedList(2);
    LinkedList *dummy1 = head1;

    for(auto it : arr1)
    {
        dummy1->next = new LinkedList(it);
        dummy1 = dummy1->next;
    }

    LinkedList *head2 = new LinkedList(5);
    LinkedList *dummy2 = head2;

    for(auto it : arr2)
    {
        dummy2->next = new LinkedList(it);
        dummy2 = dummy2->next;
    }

    cout << "List 1: ";
    displayLinkedList(head1);

    cout << "List 2: ";
    displayLinkedList(head2);

    LinkedList *result = addTwoNumbers(head1, head2);

    cout << "Result: ";
    displayLinkedList(result);

    return 0;
}