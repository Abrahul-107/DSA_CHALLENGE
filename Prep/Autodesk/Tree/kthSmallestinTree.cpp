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

void inorderTraversal(vector<int>&ans,TreeNode *root)
{
    if(root==nullptr)
        return ;
    inorderTraversal(ans,root->left);
    ans.push_back(root->data);
    inorderTraversal(ans,root->right);
}


int kthSmallest(TreeNode *root,int k)
{
    vector<int>ans;
    inorderTraversal(ans,root);
    return ans[k-1];

}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    cout<<kthSmallest(root,1);

    return 0;
}