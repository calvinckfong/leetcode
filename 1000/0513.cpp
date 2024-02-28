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
// 513. Find Bottom Left Tree Value
class Solution {
public:
    vector<int> dfs(TreeNode* node, int depth)
    {
        if (!node->left && !node->right) return {depth, node->val};
        vector<int> val1(2, 0), val2(2, 0);
        if (node->left)
        {
            val1 = dfs(node->left, depth+1);
        }
        if (node->right)
        {
            val2 = dfs(node->right, depth+1);
        }

        return (val2[0]>val1[0])?val2:val1;
    }

    int findBottomLeftValue(TreeNode* root) {
        return dfs(root, 0)[1];
    }
};
