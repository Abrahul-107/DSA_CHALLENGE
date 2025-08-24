#include<iostream>
using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val):data(val),left(nullptr),right(nullptr){}
    ~TreeNode()
    {
        delete left;
        delete right;

    }

};

int countNode = 0;

void dfs(TreeNode*root,int k,int &result)
{
    if(!root)
        return ;
    
    dfs(root->left,k,result);
    countNode++;
    if(countNode==k)
    {
        result = root->data;
        return;
    }
    dfs(root->right,k,result);

    
}

int kthSmallestElementInBST(TreeNode *root,int k)
{
    int result = 0;
    dfs(root,k,result);
    if(result == 0)
        return -1;
    return result;

}



int main()
{
    TreeNode *node = new TreeNode(4);
    node->left = new TreeNode(2);
    node->left->left = new TreeNode(1);
    node->left->right = new TreeNode(3);
    node->right = new TreeNode(6);
    node->right->left = new TreeNode(5);
    node->right->right  = new TreeNode(7);
    cout<<kthSmallestElementInBST(node,3);

    delete node;

    return 0;


}