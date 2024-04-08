#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:

    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool helper(TreeNode *root, int &count) {
    if (root == nullptr)
        return true;

    bool leftUnival = helper(root->left, count);
    bool rightUnival = helper(root->right, count);

    
    if ((root->left == nullptr || (leftUnival && root->data == root->left->data)) &&
        (root->right == nullptr || (rightUnival && root->data == root->right->data))) {
        count++; 
        return true;
    }

    return false;
}

int countSingleValuedSubtree(TreeNode *root) {
    int count = 0;
    helper(root, count);
    return count;
}


int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(4);

    cout<< countSingleValuedSubtree(root);

    return 0;
}
