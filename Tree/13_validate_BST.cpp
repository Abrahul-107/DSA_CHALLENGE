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

void inOrder(TreeNode *root, vector<int> &v)
{
    if (root == nullptr)
        return;
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}

bool validateBst(TreeNode *root)
{
    vector<int> forcheck;
    inOrder(root, forcheck);

    for (int i = 1; i < forcheck.size(); i++)
    {
        if (forcheck[i] <= forcheck[i - 1])
            return false;
    }

    return true;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    // root->right->left = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(19);

    if (validateBst(root))
        cout << "It is a valid binary search tree" << endl;
    else
        cout << "It is not a valid binary search tree" << endl;

    return 0;
}