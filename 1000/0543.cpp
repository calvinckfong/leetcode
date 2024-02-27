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
// 543. Diameter of Binary Tree
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        dfs(root, dia);
        return dia;
    }

    int dfs(TreeNode* node, int &dia)
    {
        if (!node) return 0;
        int depthL = dfs(node->left, dia);
        int depthR = dfs(node->right, dia);
        dia = max(dia, depthL+depthR);
        return 1 + max(depthL, depthR);
    }
};
