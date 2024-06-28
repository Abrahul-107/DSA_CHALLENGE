#include <bits/stdc++.h>
using namespace std;


//Struct for linkedlist construction
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() 
    {
        delete next;
    }
};

//Function for printing the list 
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

//Function which return the list after merge all the sorted list
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    int n = lists.size();
    for(int i=0;i<n;i++)
    {
        while(lists[i])
        {
            pq.push(lists[i]->val);
            lists[i] = lists[i]->next;
        }
    }
    ListNode *current = new ListNode(0);
    ListNode *forreturn = current;

    while(!pq.empty())
    {
        current->next = new ListNode(pq.top());
        pq.pop();
        current = current->next;
    }
    return forreturn->next;

}

//Driver code
int main() 
{
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));
    
    vector<ListNode*> lists = {l1, l2, l3};

    ListNode* mergedList = mergeKLists(lists);

    printList(mergedList); 


    //For freeup the space after the program executioon
    delete mergedList;
    delete l1;
    delete l2;
    delete l3;

    

    return 0;
}