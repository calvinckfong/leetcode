// 2583. Kth Largest Sum in a Binary Tree
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;

        while (!q.empty()) {
            lvl++;
            int n = q.size();
            long long sum=0LL;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)     q.push(node->left);
                if (node->right)    q.push(node->right);
            }
            pq.push(sum);
        }
        if (lvl<k) return -1;
        while (--k) pq.pop();
        return pq.top();
    }
};
