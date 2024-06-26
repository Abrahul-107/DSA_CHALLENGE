#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:

    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val):data(val),left(nullptr),right(nullptr){};

};
void printInorder(TreeNode *root)
{
    if(root==NULL) return ;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
void inorderTraversal(TreeNode *root,vector<TreeNode*>&sortedArray)
{
    if(root==nullptr) return  ;
    inorderTraversal(root->left,sortedArray);
    sortedArray.push_back(root);
    inorderTraversal(root->right,sortedArray);
}
TreeNode* sortedArrayToBst(int start,int end,vector<TreeNode*>sortedArray)
{
    if(start>end)
        return nullptr;
    int mid = (start+end)/2;
    TreeNode *root = sortedArray[mid];
    root->left = sortedArrayToBst(start,mid-1,sortedArray);
    root->right = sortedArrayToBst(mid+1,end,sortedArray);
    return root;
    
    
}
TreeNode* balanceBST(TreeNode* root) 
{
    vector<TreeNode*>sortedArray;
    inorderTraversal(root,sortedArray);
    return sortedArrayToBst(0,sortedArray.size()-1,sortedArray);
}


int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    TreeNode *newnode = balanceBST(root);
    printInorder(newnode);    
    
    //For deleting allocating memory
    for(TreeNode* node : vector<TreeNode*>{root, root->right, root->right->right, root->right->right->right}) 
        delete node;

    return 0;
}