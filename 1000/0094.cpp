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
// 94. Binary Tree Inorder Traversal
class Solution {
public:
    void Traversal(TreeNode* node, vector<int>& result)
    {
        if (node)
        {
            if (node->left != nullptr)
                Traversal(node->left, result);
            result.push_back(node->val);
            if (node->right != nullptr)
                Traversal(node->right, result);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        Traversal(root, result);

        return result;
    }
};
