#include <bits/stdc++.h>
using namespace std;

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr){};
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

TreeNode *arrayToBst(int *arr, int start, int end)
{
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(arr[mid]);

    root->left = arrayToBst(arr, start, mid - 1);
    root->right = arrayToBst(arr, mid + 1, end);

    return root;
}

void inOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode *root = arrayToBst(arr, 0, n);
    inOrder(root);

    delete root;
    return 0;
}