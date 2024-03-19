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

void levelOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    queue<TreeNode *> levelq;
    levelq.push(root);

    while (!levelq.empty())
    {
        TreeNode *current = levelq.front();
        levelq.pop();
        cout << current->data << " ";
        if (current->left != nullptr)
            levelq.push(current->left);
        if (current->right != nullptr)
            levelq.push(current->right);
    }
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

    levelOrderTraversal(root);

    delete root;

    return 0;
}
