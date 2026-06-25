#include<iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void invertBinaryTree(TreeNode *root)
{
    if(root==nullptr)
        return;
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
    swap(root->left,root->right);
}

void preorderTraversal(TreeNode *root)
{
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    preorderTraversal(root);
    invertBinaryTree(root);
    cout<<endl;
    preorderTraversal(root);


    return 0;

}