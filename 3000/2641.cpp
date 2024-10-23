// 2641. Cousins in Binary Tree II
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;

        // first pass
        vector<long long> levelSums;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;
            while (n--) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if (node->left)     q.push(node->left);
                if (node->right)    q.push(node->right);
            }
            levelSums.push_back(sum);
        }

        // second pass
        int currLevel = 1;
        q.push(root);
        root->val = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* node = q.front(); q.pop();
                long long sum = 0;
                if (node->left) {
                    q.push(node->left);
                    sum += node->left->val;
                }
                if (node->right) {
                    q.push(node->right);
                    sum += node->right->val;
                }
                if (node->left) {
                    node->left->val = levelSums[currLevel] - sum;
                }
                if (node->right) {
                    node->right->val = levelSums[currLevel] - sum;
                }
            }
            currLevel++;
        }
        return root;
    }
};
