#include<iostream>
using namespace std;

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val):data(val),left(nullptr),right(nullptr){}


};

void invertBinaryTree(TreeNode *root)
{
    if(!root)
        return;
    swap(root->left,root->right);
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);

}

void inorder(TreeNode *root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    

    inorder(root);
    cout<<endl;
    invertBinaryTree(root);
    inorder(root);

    return 0;

}