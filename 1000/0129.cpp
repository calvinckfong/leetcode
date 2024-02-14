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
// 129. Sum Root to Leaf Numbers
class Solution {
public:
    int sum(TreeNode* node, int prev)
    {
        if (!node->left && !node->right)
            return 10*prev + node->val;
        
        int result = 0;
        if (node->left) 
            result += sum(node->left, 10*prev+node->val);
        if (node->right)
            result += sum(node->right, 10*prev+node->val);
        return result;
    }

    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
    }
};
