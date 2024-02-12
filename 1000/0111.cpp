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
// 111. Minimum Depth of Binary Tree
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;    // this is a empty tree
        if (!root->left && !root->right) return 1;  // this is a leaf node
        if (!root->left && root->right) return minDepth(root->right) + 1; // only right branch
        if (!root->right && root->left) return minDepth(root->left) + 1; // only left branch
        return min(minDepth(root->left), minDepth(root->right)) + 1; // find the branch with minimum depth
    }
};
