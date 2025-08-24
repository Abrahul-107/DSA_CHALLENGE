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

void bfsTraversal(TreeNode *root)
{
    if (!root)
        return ;
    
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout<<node->data<<" ";

        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);

    }

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

    bfsTraversal(root);
    return 0;
}