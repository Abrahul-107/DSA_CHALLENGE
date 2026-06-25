#include<iostream>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }

};

void preOrderTraversal(TreeNode*root)
{
    if(root==nullptr)
        return;
    cout<<root->value<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}



int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(11);
    root->right->left = new TreeNode(1);

    preOrderTraversal(root);
    //1,3,7,11,5,1



    return 0;
}