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

LinkedList *cyclePoint(LinkedList*head)
{
    LinkedList *slow = head;
    LinkedList *fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(slow==fast)
        {
            slow = head;
            while (slow!=fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
            
        }
    }
    return nullptr;
    
}

int main()
{
    LinkedList* list = new LinkedList(2);
    list->next = new LinkedList(3);
    list->next->next = new LinkedList(4);
    list->next->next->next = new LinkedList(5);
    list->next->next->next->next = new LinkedList(6);
    list->next->next->next->next->next = list->next;

    LinkedList *newNode = cyclePoint(list);
    cout<<newNode->data;




    return 0;

}