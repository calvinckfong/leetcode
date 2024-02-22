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
// 98. Validate Binary Search Tree
class Solution {
public:
    bool validate(TreeNode* node, long lower, long upper)
    {
        if (!node) return true;
        if (node->val<=lower || node->val>=upper) return false;

        return validate(node->left, lower, node->val) &&
            validate(node->right, node->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};
