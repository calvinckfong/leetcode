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
// 102. Binary Tree Level Order Traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        int qsize;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            qsize = q.size();
            vector<int> tmp;
            while (qsize--)
            {
                TreeNode *node = q.front(); q.pop();
                if (node)
                {
                    tmp.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (tmp.size()>0)
                result.push_back(tmp);
        }
        return result;
    }
};
