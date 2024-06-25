#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : data(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : data(val), left(nullptr), right(nullptr){};
};

int sum = 0;

void dfs(TreeNode *root)
{
    if (root)
    {
        dfs(root->right);
        sum += root->data;
        root->data = sum;
        dfs(root->left);
    }
}

TreeNode *convertBST(TreeNode *root)
{
    sum = 0; 
    dfs(root);
    return root;
}

void printTreeBFS(TreeNode *root)
{
    if (root == nullptr)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    root->left->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(8);

    TreeNode *newroot = convertBST(root);

    printTreeBFS(newroot);
    cout << endl;

    return 0;
}
