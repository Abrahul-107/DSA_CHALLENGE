#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *sortedListToBST(Node *head)
{
    if (!head)
        return nullptr;
    if (!head->next)
        return new TreeNode(head->data);

    // Find mid and make it root
    Node *slow = head;
    Node *fast = head;
    Node *slow_prev = nullptr;
    while (fast && fast->next)
    {
        slow_prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    TreeNode *root = new TreeNode(slow->data); // Make root
    if (slow_prev)
        slow_prev->next = nullptr; // We only want left half of linked list for left subtree

    root->left = sortedListToBST(head);       // Make left subtree
    root->right = sortedListToBST(slow->next); // Make right subtree

    return root; // Return root
}

void inorderTraversal(TreeNode *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Converting the sorted linked list to a balanced binary search tree
    TreeNode *root = sortedListToBST(head);

    // Printing the inorder traversal of the resultant BST
    cout << "Inorder traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    // Clean up memory
    delete head;
    // Free memory used by the tree
    // Implement a function to delete the tree nodes
    // For simplicity, not implemented here
    return 0;
}
