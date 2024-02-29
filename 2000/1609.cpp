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
// 1609. Even Odd Tree
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int depth=0, qSize, minVal, maxVal;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            qSize = q.size();
            minVal = INT_MAX;
            maxVal = INT_MIN;
            while (qSize--)
            {
                TreeNode* node = q.front(); q.pop();
                if (node->val%2 == depth%2) {return false;}
                if (depth%2) // odd level, even and decreasing
                {
                    if (minVal<=node->val) {return false;}
                    else minVal = node->val;
                }
                else // even level, odd and increasing
                {
                    if (maxVal>=node->val) {return false;}
                    else maxVal = node->val;
                }
                // Add nodes of next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        return true;
    }
};
