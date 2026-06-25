#include<iostream>
using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


void inorderTraversal(TreeNode *root)
{
    if(root==nullptr)
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
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    inorderTraversal(root);


    return 0;
}