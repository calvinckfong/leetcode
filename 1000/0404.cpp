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
// 404. Sum of Left Leaves
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int result=0;
        
        if (root->right)
            result += sumOfLeftLeaves(root->right);
        if (root->left) {
            if (root->left->left || root->left->right)
                result += sumOfLeftLeaves(root->left);
            else
                result += root->left->val;
        }

        return result;
    }
};
