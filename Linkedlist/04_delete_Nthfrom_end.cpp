/*Given the head of a linked list, remove the nth node from the end of the list and return its head.*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* deleteNthFromEnd(ListNode* head,int n) 
{
    if(head==NULL)
        return NULL;

        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL)
        {   temp = temp->next;
            len++;

        }
        if(len==n)
        return head->next;

        int i = 1;
        for(temp= head;i<len-n;i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    
}


int main() 
{
   
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(6);
    l1->next->next->next->next = new ListNode(8);




    ListNode* result = deleteNthFromEnd(l1,3);

    
    while (result != nullptr) 
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}