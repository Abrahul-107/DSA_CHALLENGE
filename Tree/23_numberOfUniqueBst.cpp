#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;          
    TreeNode *left;    
    TreeNode *right;   

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int numTreeRecursion(int n) {
    // Base case: If there are 0 or 1 nodes, there is exactly one BST possible
    if (n <= 1)
        return 1;

    int ans = 0;
    
    // Recursively calculate the number of unique BSTs for each possible root
    for (int i = 1; i <= n; i++) {
        // The number of unique BSTs with `i` as the root is the product of the number
        // of unique BSTs in the left (i-1 nodes) and right (n-i nodes) subtrees
        ans += numTreeRecursion(i - 1) * numTreeRecursion(n - i);
    }
    
    return ans;
}

int numTreeMemo(int n, vector<int>& dp) {
    // Base case: If there are 0 or 1 nodes, there is exactly one BST possible
    if (n <= 1)
        return 1;

    // Return the stored result if it has already been computed
    if (dp[n] != -1)
        return dp[n];

    int res = 0;
    
    // Recursively calculate the number of unique BSTs for each possible root
    for (int i = 1; i <= n; i++) {
        // The number of unique BSTs with `i` as the root is the product of the number
        // of unique BSTs in the left (i-1 nodes) and right (i+1....n nodes) i:e (n-i) subtrees
        res += numTreeMemo(i - 1, dp) * numTreeMemo(n - i, dp);
    }
    
    // Store the computed result in dp array
    return dp[n] = res;
}

int main() {
    int n = 3;  
    vector<int> dp(n + 1, -1); 

    cout << "Number of unique BSTs (recursion): " << numTreeRecursion(n) << endl;
    cout << "Number of unique BSTs (memoization): " << numTreeMemo(n, dp) << endl;

    return 0;
}
