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
// 623. Add One Row to Tree
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
        {
            root = new TreeNode(val, root, nullptr);
        }
        else
        {
            int currDepth = 0;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                int qsize = q.size();
                currDepth++;

                if (currDepth+1 == depth)
                {
                    // Insert new nodes in this level
                    for (int i=0; i<qsize; i++)
                    {
                        TreeNode* curr = q.front();
                        q.pop();
                        if (curr->left) {
                            TreeNode* newNode = new TreeNode(val, curr->left, nullptr);
                            curr->left = newNode;
                        }
                        else 
                        {
                            curr->left = new TreeNode(val);
                        }
                        
                        if (curr->right) {
                            TreeNode* newNode = new TreeNode(val, nullptr, curr->right);
                            curr->right = newNode;
                        }
                        else
                        {
                            curr->right = new TreeNode(val);
                        }
                    }
                }
                else
                {
                    // Queue child nodes
                    for (int i=0; i<qsize; i++)
                    {
                        TreeNode* curr = q.front();
                        q.pop();
                        if (curr->left) q.push(curr->left);
                        if (curr->right) q.push(curr->right);
                    }
                }
            }
        }

        
        return root;
    }
};
