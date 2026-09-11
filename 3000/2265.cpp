// 2265. Count Nodes Equal to Average of Subtree
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }

private:
    int res = 0;
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [ls, lc] = dfs(node->left);
        auto [rs, rc] = dfs(node->right);
        int sum = ls + rs + node->val;
        int cnt = lc + rc + 1;
        if (sum / cnt == node->val)
            res++;
        return {sum, cnt};
    }
};
