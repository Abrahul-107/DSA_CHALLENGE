#include<bits/stdc++.h>
using namespace std;

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val): data(val),left(nullptr),right(nullptr){};

};

void postorder(TreeNode *root)    
{
    if(root==nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right  = new TreeNode(12);
    root->right = new TreeNode(10);
    root->right->left  = new TreeNode(30);
    root->right->right = new TreeNode(40);


    postorder(root);

}