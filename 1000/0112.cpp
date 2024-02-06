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
// 112. Path Sum
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // reach leaf
        if (!root->left && !root->right)
            return (targetSum==root->val);
        
        if (hasPathSum(root->left, targetSum-root->val))
            return true;
        
        if (hasPathSum(root->right, targetSum-root->val))
            return true;

        return false;
    }
};
