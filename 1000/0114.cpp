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
// 114. Flatten Binary Tree to Linked List
class Solution {
public:
    // TreeNode* oldRight = nullptr;
    void flatten(TreeNode* root) {
        TreeNode* tempRight, *node;
        if (root)
        {
            // keep right branch
            tempRight = root->right;
            // move left branch to right
            root->right = root->left;
            root->left = nullptr;
            
            // move previous left nodes to the right
            node = root;
            while (node->right)
                node = node->right;

            // append old right branch to the end
            node->right = tempRight;
            flatten(root->right);
        }
    }
};
