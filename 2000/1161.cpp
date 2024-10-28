// 1161. Maximum Level Sum of a Binary Tree
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int result = -1, maxSum = INT_MIN, depth=1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n=q.size(), sum=0;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum>maxSum) {
                maxSum = sum;
                result = depth;
            }
            depth++;
        }
        return result;
    }
};
