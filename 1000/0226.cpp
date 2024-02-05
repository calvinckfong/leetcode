/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 226. Invert Binary Tree
class Solution {
public:
    void SwapBranch(TreeNode* root)
    {
        if (root && (root->left || root->right))
        {
            swap(root->left, root->right);
            SwapBranch(root->left);
            SwapBranch(root->right);
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        SwapBranch(root);
        return root;
    }
};
