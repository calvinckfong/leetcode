/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 637. Average of Levels in Binary Tree
class Solution {
public:
    vector<double> sum;
    vector<double> count;
    void sumLevel(int depth, TreeNode* node) {
        if (node) {
            if (count.size() < depth+1)
            {
                sum.push_back(node->val);
                count.push_back(1);
            }
            else
            {
                sum[depth] += node->val;
                count[depth] ++;
            }

            sumLevel(depth+1, node->left);
            sumLevel(depth+1, node->right);
        }
    }

    vector<double> averageOfLevels(TreeNode* root) {
        int depth = 0;
        sumLevel(depth, root);

        for (int i=0; i<count.size(); i++)
            sum[i] /= count[i];
        return vector<double>(sum.begin(), sum.end());
    }
};
