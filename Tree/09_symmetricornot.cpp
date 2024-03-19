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

bool isSymmetricOrNot(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1->data == root2->data && root1 && root2)
        return isSymmetricOrNot(root1->left, root2->right) && isSymmetricOrNot(root1->right, root2->left);

    return false;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetricOrNot(root, root))
        cout << "Tree is symmetric " << endl;
    else
        cout << "Not symmetric " << endl;

    delete root;

    return 0;
}