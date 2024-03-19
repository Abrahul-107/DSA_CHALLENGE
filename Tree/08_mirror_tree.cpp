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
void mirrorTree(TreeNode *root)
{
    if(root==nullptr)
    return;

    mirrorTree(root->left);
    mirrorTree(root->right);

    swap(root->left,root->right);


}
void inOrder(TreeNode* node)
{
    if (node == NULL)
        return;
 
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    mirrorTree(root);
    inOrder(root);

    delete root;

    return 0;

    
}