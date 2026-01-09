// 865. Smallest Subtree with all the Deepest Nodes
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).first;
    }

private:
    pair<TreeNode*, int> solve(TreeNode* root) {
        if (!root) return {nullptr, 0};

        auto l = solve(root->left);
        auto r = solve(root->right);

        if (l.second == r.second) {
            return {root, max(l.second, r.second)+1};
        } else if (l.second > r.second) {
            return {l.first, l.second+1};
        } else {
            return {r.first, r.second+1};
        }
    }
};
