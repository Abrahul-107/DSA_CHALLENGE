#include <bits/stdc++.h>
using namespace std;

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr){};
};

// Using DFS
int maximumDepthOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int lside = maximumDepthOfBinaryTree(root->left) + 1;
    int rside = maximumDepthOfBinaryTree(root->right) + 1;

    int ans = lside > rside ? lside : rside;
    return ans;
}

// Using BFS
int maximumDepthOfBinaryBFS(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    int c1 = 0, c2 = 0;

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        if (current->left != nullptr)
        {
            q.push(current->left);
            c1++;
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
            c2++;
        }
    }
    return max(c1, c2);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(12);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(40);
    root->right->right->right = new TreeNode(50);

    cout << "Maximum depth of this binary tree is : ";
    cout << "BFS: " << maximumDepthOfBinaryBFS(root) << endl;
    cout << "DFS: " << maximumDepthOfBinaryTree(root) << " ";

    delete root;

    return 0;
}