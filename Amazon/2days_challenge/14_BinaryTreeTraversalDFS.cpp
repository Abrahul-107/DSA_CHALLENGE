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

void postOrderTraversal(TreeNode *root)
{
    if(!root)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void preOrderTraversal(TreeNode *root)
{
    if(!root)
        return;
    
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}

void inorderTraversal(TreeNode *root)
{
    if(!root)
        return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->left->left->right = new TreeNode(7);

    preOrderTraversal(root);cout<<endl;
    inorderTraversal(root);cout<<endl;
    postOrderTraversal(root);cout<<endl;

    return 0;



}