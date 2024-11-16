// 257. Binary Tree Paths
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        result.clear();
        if (root) solve(root, to_string(root->val));
        return result;
    }

private:
    vector<string> result;

    void solve(TreeNode* node, string prev) {
        if (!node->left && !node->right) {
            result.push_back(prev);
            return;
        }

        if (node->left) {
            solve(node->left, prev + "->" + to_string(node->left->val));
        }
        if (node->right) {
            solve(node->right, prev + "->" + to_string(node->right->val));
        }
    }
};
