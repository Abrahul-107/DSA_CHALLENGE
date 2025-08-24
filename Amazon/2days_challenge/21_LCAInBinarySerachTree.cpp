#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}

    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

TreeNode *lowestCommonAncestorInBst(TreeNode *root,TreeNode*p,TreeNode*q)
{

    while(root)
    {
        int value = root->data;
        int leftValue = p->data;
        int rightValue = q->data;

        if(leftValue > value && rightValue > value)
            root = root->right;
        else if(leftValue<value && rightValue<value)
            root = root->left;
        else
            return root;
        
    }
    return nullptr;
} 

int main()
{
    // Creating the BST manually
    TreeNode* root = new TreeNode(6);
    
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    TreeNode *left = root->left;
    TreeNode *right = root->right ;


    

    cout << "BST created successfully!" << endl;

    TreeNode *ans = lowestCommonAncestorInBst(root,left,right);
    cout<<ans->data;
    delete root;

    return 0;
}
