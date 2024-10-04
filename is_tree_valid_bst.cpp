#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBSTHelper(TreeNode* node, long minVal, long maxVal) 
{
    if (node == NULL)
        return true;
    
    if (node->val <= minVal || node->val >= maxVal)
        return false;

    return isValidBSTHelper(node->left, minVal, node->val) && isValidBSTHelper(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root) 
{
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

int main() 
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if (isValidBST(root)) 
        cout << "True" << endl;
    else 
        cout << "False" << endl;
    

    return 0;
}

// Time Complexity :- O(n) -------- n = number of nodes
// Space Complexity :- O(h) -------- h = height of tree
