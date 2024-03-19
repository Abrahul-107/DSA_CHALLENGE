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

bool identicalOrNot(TreeNode *root1, TreeNode *root2)
{

    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    if (root1->data != root2->data)
        return false;

    bool tree1 = identicalOrNot(root1->left, root2->left);
    bool tree2 = identicalOrNot(root1->right, root2->right);

    return tree1 && tree2;
}
int main()
{
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);

    if (identicalOrNot(root1, root2))
        cout << "Both tree are identical ";
    else
        cout << "Not identical " << endl;

    delete root1;
    delete root2;

    return 0;
}