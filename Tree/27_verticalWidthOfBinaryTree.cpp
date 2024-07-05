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

int verticalWidth(TreeNode *root)
{
    set<int>st;
    queue<pair<TreeNode*,int>>q;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        auto frontt = q.front();
        q.pop();
        TreeNode *node = frontt.first;
        int col = frontt.second;
        st.insert(col);


        if(node->left)
            q.push(make_pair(node->left,col-1));
        if(node->right)
            q.push(make_pair(node->right,col+1));

    }
    return st.size();

}


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);


    cout<<"The total vertical width is "<<verticalWidth(root)<<endl;

    

    return 0;

}