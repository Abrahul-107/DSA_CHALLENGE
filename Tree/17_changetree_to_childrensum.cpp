#include <bits/stdc++.h>
using namespace std;

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr){};
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

void changeTreeToChildrenSum(TreeNode *root)
{
    if(root==nullptr)
        return ;
    int sum = 0;
    if(root->left)
        sum += root->left->data;
    if(root->right)
        sum += root->right->data;
    if(sum>=root->data) 
        root->data = sum;
    else
    {
        if(root->left)
            root->left->data = root->data; 
        if(root->right)
            root->right->data = root->data;
    }
    changeTreeToChildrenSum(root->left);
    changeTreeToChildrenSum(root->right);

    int total = 0 ;
    if(root->left)
        total += root->left->data;
    if(root->right)
        total += root->right->data;
    if(root->left or root->right)
        root->data = total;

}
void inOrder(TreeNode *root)
{
    if(root==nullptr)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(35);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right  = new TreeNode(2);

    changeTreeToChildrenSum(root);
    inOrder(root);


    delete root;

    return 0;

}