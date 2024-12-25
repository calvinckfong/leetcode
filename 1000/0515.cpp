// 515. Find Largest Value in Each Tree Row
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int maxVal = INT_MIN;
            int n = q.size();
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                maxVal = max(maxVal, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(maxVal);
        }
        return result;
    }
};
