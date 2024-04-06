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

void LeftViewOfBinaryTree(TreeNode *root, int level, vector<int> &ans)
{
    if(root == nullptr)
        return;

    if(ans.size() == level)
        ans.push_back(root->data);

    LeftViewOfBinaryTree(root->right, level + 1, ans);
    LeftViewOfBinaryTree(root->left, level + 1, ans);
    
}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(54);
    root->left->right = new TreeNode(45);

    vector<int> ans;
    LeftViewOfBinaryTree(root, 0, ans);

    for(int val : ans) 
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
