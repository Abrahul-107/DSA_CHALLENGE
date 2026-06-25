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

int maximumDepthOfBinaryTree(TreeNode *root)
{
    if(root==nullptr)
        return 0;
    int lside = maximumDepthOfBinaryTree(root->left);
    int rside = maximumDepthOfBinaryTree(root->right);
    return 1+max(lside,rside);
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
    cout<<maximumDepthOfBinaryTree(root);


    return 0;

}