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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==nullptr || root==p ||root==q) 
        return root;
    
    TreeNode *leftPtr = lowestCommonAncestor(root->left,p,q);
    TreeNode *rightPtr = lowestCommonAncestor(root->right,p,q);

    if(leftPtr==nullptr)
        return rightPtr;
    else if(rightPtr==nullptr)
        return leftPtr;
    else
        return root;
        
    return nullptr;
}

int main()
{
    // Create a sample tree:
    //        3
    //       / \
    //      5   1
    //     / \ / \
    //    6  2 0  8
    //      / \
    //     7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Test nodes
    TreeNode* p = root->left;              // Node 5
    TreeNode* q = root->left->right->right; // Node 4

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca)
        cout << "LCA of " << p->data << " and " << q->data << " is: " << lca->data << endl;
    else
        cout << "LCA not found." << endl;

    delete root;
    return 0;
}
