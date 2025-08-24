#include <iostream>
using namespace std;

class LinkedList
{
public:
    int data;
    LinkedList *next;

    LinkedList(int val) : data(val), next(nullptr) {}
    ~LinkedList()
    {
        delete next;
    }
};

// Helper function to create a linked list from an array
LinkedList *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    LinkedList *head = new LinkedList(arr[0]);
    LinkedList *current = head;
    for (int i = 1; i < n; ++i)
    {
        current->next = new LinkedList(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(LinkedList *head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

LinkedList *addTwoNumber(LinkedList *l1,LinkedList *l2)
{
    LinkedList *resultList = new LinkedList(0);
    LinkedList *currentList =resultList;
    int carry = 0;

    while (l1 || l2 || carry ==1 )
    {
        int sum = 0;
        if(l1)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if(l2)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry ;
        carry = sum/10;
        LinkedList *newNode = new LinkedList(sum%10);
        currentList->next = newNode;
        currentList = currentList->next;
    }
    return resultList->next;

}

int main()
{
    int arr1[] = {2, 4, 3}; 
    int arr2[] = {5, 6, 4}; 

    LinkedList *l1 = createLinkedList(arr1, 3);
    LinkedList *l2 = createLinkedList(arr2, 3);


    LinkedList *ans = addTwoNumber(l1, l2);
    printLinkedList(ans);

    // Free memory
    delete l1;
    delete l2;
    delete ans;

    return 0;
}
