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

// 437. Path Sum III
class Solution {
public:
    int dfs(TreeNode* node, long long targetSum)
    {
        if (!node) return 0;
        int result = 0;
        if (node->val == targetSum) result++;
           
        // use long long to resolve large numbers
        long long diff = targetSum-node->val;
        result += dfs(node->left, diff);
        result += dfs(node->right, diff);
        return result;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int result = 0;
        if (root)
        {
            result += dfs(root, targetSum);
            result += pathSum(root->left, targetSum);
            result += pathSum(root->right, targetSum);
        }
        return result;
    }
};
