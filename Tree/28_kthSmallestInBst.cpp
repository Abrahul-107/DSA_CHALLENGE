#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

//Function to insert a value into the BST
TreeNode *insert(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

//Function to calculate the kthsmallest
void returnKthSmallest(TreeNode *root, int k, int &count, int &ans)
{
    if (root == nullptr)
        return;
    returnKthSmallest(root->left, k, count, ans);
    count++;
    if (count == k)
    {
        ans = root->data;
        return;
    }
    returnKthSmallest(root->right, k, count, ans);
}
int kthSmallestInBst(TreeNode *root, int k)
{
    int count = 0;
    int ans = -1;
    returnKthSmallest(root, k, count, ans);
    return ans;
}

//In-order traversal of the BST (for testing)
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
    TreeNode *root = nullptr;

    //Insert values into the BST
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    //Print the in-order traversal of the BST
    inOrder(root);
    cout << endl;
    cout<<kthSmallestInBst(root,4);

    return 0;
}
