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

long long previousValue = LLONG_MIN;

bool validateBST(TreeNode *root)
{
    if(!root)
        return true;

    if(!validateBST(root->left))
        return false;
    if(root->data <= previousValue)
        return false;
    
    previousValue = root->data;
    return validateBST(root->right);

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
    cout<<validateBST(root);

    return 0;

}