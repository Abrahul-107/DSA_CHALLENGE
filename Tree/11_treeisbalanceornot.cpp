#include<bits/stdc++.h>
using namespace std;

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val):data(val),left(nullptr),right(nullptr){};
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};
int height(TreeNode *root)
{
    if(root==nullptr)
        return 0;
    return 1+max(height(root->left),height(root->right));

}
bool balanceOrNot(TreeNode *root)
{
    if(root == nullptr)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh - rh) <= 1 && balanceOrNot(root->left) && balanceOrNot(root->right))
        return true;

    return false;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(8);

    if(balanceOrNot(root))
        cout<<"This tree is balanced "<<endl;
    else
        cout<<"Not balanced "<<endl;

    

    return 0;

}