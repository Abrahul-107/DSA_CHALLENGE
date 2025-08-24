//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

#include<bits/stdc++.h>
#include<iostream>
#include <unordered_set>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data): val(data),left(nullptr),right(nullptr){};
    ~TreeNode()
    {
        delete left;
        delete right;
    }


};


//Inorder traversal
void inorderTraversal(TreeNode *root)
{
    if(root==nullptr)
        return;
    inorderTraversal(root->left);
    cout<<root->val<<' ';
    inorderTraversal(root->right);
}


//Solution to the problem
bool dfsForFindTarget(TreeNode *root,unordered_set<int>&seen,int target)
{
    if(root==nullptr)
        return false;
    if(seen.count(target-root->val))
        return true;
    seen.insert(root->val);
    return dfsForFindTarget(root->left,seen,target) || dfsForFindTarget(root->right,seen,target);
}
bool findTarget(TreeNode *root,int target)
{
    unordered_set<int>seen;
    return dfsForFindTarget(root,seen,target);

}


int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    // inorderTraversal(root);
    cout<<findTarget(root,9);


    return 0;
}