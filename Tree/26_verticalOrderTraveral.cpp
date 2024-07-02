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

void printVerticalOrder(TreeNode *root)
{
    if(root==nullptr)
        return;
    unordered_map<int,vector<int>>ump;
    int hd = 0; //Horizantal distance

    queue<pair<TreeNode*,int>>q;
    q.push({root,hd});

    int mn =0,mx=0;

    while(!q.empty())
    {
        pair<TreeNode*,int> temp  = q.front();
        q.pop();
        hd = temp.second;
        TreeNode *node = temp.first;

        ump[hd].push_back(node->data);

        if(node->left)
            q.push({node->left,hd-1});
        if(node->right)
            q.push({node->right,hd+1});

        if(mn>hd)
            mn = hd;
        if(mx<hd)
            mx = hd;
    }
    for(int i=mn;i<=mx;i++)
    {
        vector<int>temp = ump[i];
        for(int j=0;j<temp.size();j++)
            cout<<temp[j]<<" ";
    }


}


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);

    printVerticalOrder(root);

    
    return 0;
}