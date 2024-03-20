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

bool isChildrenSumOrNot(TreeNode *root)
{
    int sum = 0;

    if (root == nullptr || (root->left == nullptr) && (root->right == nullptr))
        return true;

    else
    {
        if (root->left != nullptr)
            sum += root->left->data;
        if (root->right != nullptr)
            sum += root->right->data;

        return (sum == root->data && isChildrenSumOrNot(root->left) && isChildrenSumOrNot(root->right));
    }
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(2);

    if (isChildrenSumOrNot(root))
        cout << "Children sum property exist " << endl;
    else
        cout << "Children sum property is not exist" << endl;

    delete root;
    return 0;
}