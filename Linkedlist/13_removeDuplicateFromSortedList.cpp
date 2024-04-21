//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
#include<bits/stdc++.h>
using namespace std;

class LinkedList
{
public:
    int data;
    LinkedList *next;

    LinkedList(int val) : data(val), next(nullptr) {};
    LinkedList(int val, LinkedList *nxt) : data(val), next(nxt) {};
};

LinkedList* removeDuplicateFromSortedList(LinkedList *head)
{
    LinkedList* dummy = new LinkedList(0, head);
    LinkedList* prev = dummy;

    while (head)
    {
        if (head->next != nullptr && head->data == head->next->data)
        {
            while (head->next != nullptr && head->data == head->next->data)
                head = head->next;
            prev->next = head->next;
        }
        else
        {
            prev = prev->next;
        }
        head = head->next;
    }
    return dummy->next;
}

void display(LinkedList *head)
{
    if (!head) 
    {
        cout << "nullptr";
        return;
    }
    cout << head->data << "->";
    display(head->next);
}

int main()
{
    LinkedList *head = new LinkedList(1);
    head->next = new LinkedList(2);
    head->next->next = new LinkedList(2);
    head->next->next->next = new LinkedList(3);
    head->next->next->next->next = new LinkedList(3);
    head->next->next->next->next->next = new LinkedList(5);
    head->next->next->next->next->next->next = new LinkedList(6);

    cout << "Original List: "<<'\n';
    display(head);
    cout << '\n';

    LinkedList *ans = removeDuplicateFromSortedList(head);

    cout << "List after removing duplicates: "<<'\n';
    display(ans);
    cout << '\n';

    return 0;
}
