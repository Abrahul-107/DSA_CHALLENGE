#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

bool detectCycle(Node* head) 
{
    Node *slowPtr = head;
    Node *fastPtr = head;

    while(fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(slowPtr==fastPtr)
            return true;
    }
    return false;

    
}

int main() {
    // Hardcoded Linked List: 1 -> 2 -> 3 -> 4 -> 5
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Create a cycle:
    // 5 -> 3
    n5->next = n3;

    if (detectCycle(n1))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}