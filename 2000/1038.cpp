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
// 1038. Binary Search Tree to Greater Sum Tree
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> st;
        int sum = 0;
        fillStack(root, st);

        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            sum += node->val;
            node->val = sum;
        }
        return root;
    }

private:
    void fillStack(TreeNode* node, stack<TreeNode*>& st) {
        if (node) {
            fillStack(node->left, st);
            st.push(node);
            fillStack(node->right, st);
        }
    }
};
