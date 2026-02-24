// 1022. Sum of Root To Leaf Binary Numbers
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return solve(0, root);
    }

private:
    int solve(int k, TreeNode* node) {
        if (!node) return 0;
        k = k*2 + node->val;
        if (!node->left && !node->right) return k;
        return solve(k, node->left) + solve(k, node->right);
    }
};
