#include <iostream>
#include<vector>
#include<stack>


using namespace std;

//Idea: In preorder, once we move to the right subtree of some nodeevery next value must be greater than that node. root stores that lower bound.
//(once we found greater thn the first element of the array (which is root) thn only greater thn root should come), 

bool canRepresentBST(vector<int>& pre)
{
    stack<int>bst;
    int root = INT_MIN;
    for(int element:pre)
    {
        if(element<root)
            return false;
        while(!bst.empty() && element > bst.top())
        {
            root = bst.top();
            bst.pop();
        }
        bst.push(element);


    }
    return true;

}

int main() {
    // Valid preorder
    // vector<int> pre = {40, 30, 35, 80, 100};

    vector<int> pre = {40, 30, 35, 80, 100, 60};

    if (canRepresentBST(pre))
        cout << "Valid BST Preorder\n";
    else
        cout << "Invalid BST Preorder\n";

    return 0;
}