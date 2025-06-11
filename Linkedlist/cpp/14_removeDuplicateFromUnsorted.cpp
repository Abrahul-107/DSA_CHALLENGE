#include <iostream>
#include <unordered_set>
using namespace std;

class LinkedList
{
public:
    int data;
    LinkedList *next;

    LinkedList(int val) : data(val), next(nullptr) {}
};

void removeDuplicate(LinkedList *head)
{
    unordered_set<int> check;

    LinkedList *curr = head;
    LinkedList *prev = nullptr;

    while (curr != nullptr)
    {
        if (check.find(curr->data) != check.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            check.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;

    }
}

void displayList(LinkedList *root)
{
    while (root != nullptr)
    {
        cout << root->data << " ";
        root = root->next;
    }
}

int main()
{
    LinkedList *start = new LinkedList(5);
    start->next = new LinkedList(11);
    start->next->next = new LinkedList(11);
    start->next->next->next = new LinkedList(12);
    start->next->next->next->next = new LinkedList(11);
    start->next->next->next->next->next = new LinkedList(10);

    removeDuplicate(start);
    displayList(start);

    // // Free memory
    LinkedList *temp;
    while (start != nullptr)
    {
        temp = start;
        start = start->next;
        delete temp;
    }

    return 0;
}
