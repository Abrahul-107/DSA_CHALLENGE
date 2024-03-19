#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

int diameterOfTree(TreeNode *root, int &diameter)
{
    if (root == nullptr)
        return 0;

    // Calculate the depths of left and right subtrees
    int leftDepth = diameterOfTree(root->left, diameter);
    int rightDepth = diameterOfTree(root->right, diameter);

    // Update the diameter if the current node is part of the longest path
    diameter = max(diameter, 1+leftDepth + rightDepth);
    cout<<leftDepth<<rightDepth<<endl;

    // Return the depth of the current node
    return 1 + max(leftDepth, rightDepth);
}

int diameterGet(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int diameter = 0;
    diameterOfTree(root, diameter);
    return diameter;
}

int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    cout << "Diameter of the given binary tree (Test Case 1) is " << diameterGet(root1) << endl;
    delete root1;

    // Test Case 2
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->left->left->left = new TreeNode(6);
    root2->left->left->right = new TreeNode(7);
    root2->left->left->right->left = new TreeNode(8);
    root2->left->left->right->right = new TreeNode(9);
    cout << "Diameter of the given binary tree (Test Case 2) is " << diameterGet(root2) << endl;
    delete root2;

    // Test Case 3 (Empty tree)
    TreeNode *root3 = nullptr;
    cout << "Diameter of the given binary tree (Test Case 3) is " << diameterGet(root3) << endl;

    return 0;
}
