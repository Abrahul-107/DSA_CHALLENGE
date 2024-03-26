#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void levelOrderTraversal(TreeNode *root)
{
    if (!root)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size(); // Get the number of nodes in the current level
        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *current = q.front();
            q.pop();
            cout << current->data << " ";

            // Enqueue the left and right children of the current node, if they exist
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->left->left->right = new TreeNode(7);
    root->left->left->right->left = new TreeNode(8);
    root->left->left->right->right = new TreeNode(9);

    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);
    cout << endl;

    // Clean up dynamically allocated memory
    delete root->left->left->left;
    delete root->left->left->right->left;
    delete root->left->left->right->right;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right;
    delete root;

    return 0;
}
