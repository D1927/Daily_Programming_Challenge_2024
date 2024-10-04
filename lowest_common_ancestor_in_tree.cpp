#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q)
        return root;

    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

int main() 
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(4);

    TreeNode* p = root->left;  
    TreeNode* q = root->right; 

    TreeNode* ans = lca(root, p, q);
    if (ans != NULL)
        cout << "LCA of " << p->val << " and " << q->val << " is " << ans->val << endl;
    else
        cout << "LCA does not exist" << endl;

    return 0;
}

// Time Complexity :- O(n) -------- n = number of nodes
// Space Complexity :- O(h) -------- h = height of tree
