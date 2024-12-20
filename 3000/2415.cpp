// 2415. Reverse Odd Levels of Binary Tree
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 0);
        return root;
    }

private:
    void dfs(TreeNode* left, TreeNode* right, int lv) {
        if (!left || !right) return;

        if (lv%2 == 0) swap(left->val, right->val);

        dfs(left->left, right->right, lv+1);
        dfs(left->right, right->left, lv+1);
    }
};
