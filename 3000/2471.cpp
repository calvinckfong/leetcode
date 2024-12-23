// 2471. Minimum Number of Operations to Sort a Binary Tree by Level
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int qSize = q.size();
            vector<int> values(qSize);

            for (int i=0; i<qSize; i++) {
                TreeNode* node = q.front(); q.pop();
                values[i] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result += minSwaps(values);
        }
        return result;
    }

private:
    int minSwaps(vector<int>& values) {
        int result = 0, n=values.size();
        vector<int> sorted = values;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> pos;
        for (int i=0; i<n; i++)
            pos[values[i]] = i;

        for (int i=0; i<n; i++) {
            if (values[i] != sorted[i]) {
                result++;

                int curr = pos[sorted[i]];
                pos[values[i]] = curr;
                swap(values[curr], values[i]);
            }
        }
        return result;
    }
};
