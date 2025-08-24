#include<iostream>
#include<set>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val):data(val),left(nullptr),right(nullptr){}


};


int findSecondMinimumInSpecialBinaryTree(TreeNode *root)
{

    set<int>st;
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode *node = q.front();q.pop();

        st.insert(node->data);
        if(node->left)
        {
            q.push(node->left);
            q.push(node->right);

        }
    }
    if(st.size()<2)
        return -1;
    return *(next(st.begin()));

}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout<<findSecondMinimumInSpecialBinaryTree(root);
    
    return 0;



}