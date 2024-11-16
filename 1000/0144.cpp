// 144. Binary Tree Preorder Traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        result.clear();
        preorder(root);
        return result;
    }

private:
    vector<int> result;

    void preorder(TreeNode* node) {
        if (!node) return;
        result.push_back(node->val);
        preorder(node->left);
        preorder(node->right);
    }
};
