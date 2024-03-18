#include<bits/stdc++.h>
using namespace std;

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val):data(val),left(nullptr),right(nullptr){};

};

void preOrder(TreeNode *root)
{
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);


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


    preOrder(root);

    return 0;

}