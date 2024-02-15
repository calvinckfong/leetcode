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
// 450. Delete Node in a BST
class Solution {
public:
    int findMin(TreeNode* node)
    {
        while (node->left)
            node = node->left;
        return node->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        else if (root->val>key) 
            // target node is on the left branch
            root->left = deleteNode(root->left, key);
        else if (root->val<key) 
            // target node is on the right branch
            root->right = deleteNode(root->right, key);
        else
        {
            // traget node found, move the non-empty branch up
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else
            {
                // both nodes are non-empty, delete right node
                root->val = findMin(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};
