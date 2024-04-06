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

//Max value in each level By using DEPTH FIRST Traversal(DFS)
void helper(TreeNode*root,vector<int>&ans,int depth)
{
    if(root==nullptr)
        return;

    if(depth==ans.size())
        ans.push_back(root->data);
    else
        ans[depth] = max(ans[depth],root->data);


    helper(root->left,ans,depth+1);
    helper(root->right,ans,depth+1);

}
vector<int> maxValueInEachLevelDFS(TreeNode *root)
{
    vector<int>ans;
    cout<<sizeof(ans);
    helper(root,ans,0);
    return ans;

}



//Max value in each level By using Level Order traversal(BFS)
vector<int> maxValueInEachLevelBFS(TreeNode *root) {
    vector<int> maxValues;
    if (!root) return maxValues;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        int maxVal = INT_MIN;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            maxVal = max(maxVal, curr->data);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        maxValues.push_back(maxVal);
    }

    return maxValues;
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

    vector<int>res = maxValueInEachLevelBFS(root);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";


    return 0;
}