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

vector<int> iterativeInorderTraversal(TreeNode *root)
{
    vector<int>inorder;
    stack<TreeNode*>st;
    TreeNode *curr = root;

    while(curr!= nullptr || !st.empty())
    {
        while(curr!=nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        inorder.push_back(curr->data);
        curr = curr->right;
    }
}
int main()
{
    class TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    vector<int> inOrder;
    inOrder = iterativeInorderTraversal(root);
    for(auto &it:inOrder)
        cout<<it<<" ";

    return 0;
    delete root;
    
}
