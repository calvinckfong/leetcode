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
// 104. Maximum Depth of Binary Tree
class Solution {
public:
    int GetDepth(TreeNode* node, int depth)
    {
        if (!node)  return depth;

        int dl = GetDepth(node->left, depth+1);
        int dr = GetDepth(node->right, depth+1);
        return max(dl, dr);
    }
    int maxDepth(TreeNode* root) {
        return GetDepth(root, 0);
    }
};
