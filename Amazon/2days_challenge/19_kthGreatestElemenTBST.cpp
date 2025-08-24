#include<iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val):data(val),left(nullptr),right(nullptr){}

    ~TreeNode()
    {
        delete left;
        delete right;
    }

};


int kthGreatestElement()
{

}



int main()
{
    
    TreeNode *node = new TreeNode(4);
    node->left = new TreeNode(2);
    node->left->left = new TreeNode(1);
    node->left->right = new TreeNode(3);
    node->right = new TreeNode(6);
    node->right->left = new TreeNode(5);
    node->right->right  = new TreeNode(7);

    return 0;

}