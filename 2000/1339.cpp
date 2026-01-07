// 1339. Maximum Product of Splitted Binary Tree
class Solution {
public:
    int maxProduct(TreeNode* root) {
        const long MOD = 1e9 + 7;
        long sum = dfs(root), res = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) continue;

            long cur = (sum - node->val) * node->val;
            res = max(cur, res);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return res % MOD;
    }


private:
    long dfs(TreeNode* node) {
        if (!node) return 0;
        node->val += dfs(node->left) + dfs(node->right);
        return node->val;
    }
};
