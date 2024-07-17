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
// 1110. Delete Nodes And Return Forest
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        // use hash to speed up searching
        set<int> hash(to_delete.begin(), to_delete.end());
        solve(root, result, hash, true);
        return result;
    }

    TreeNode* solve(TreeNode* node, vector<TreeNode*>& result, set<int>& to_delete, bool isRoot) {
        if (node==NULL) return NULL;
        bool found = to_delete.find(node->val) != to_delete.end();

        // it is a new tree iff it is a root-node and not to be deleted 
        if (isRoot && !found) result.push_back(node);

        // continue to search its children
        // if current is deleted, its non-leaf children will be a new tree
        node->left  = solve(node->left,  result, to_delete, found);
        node->right = solve(node->right, result, to_delete, found);
        
        return (found) ? NULL : node;
    }
};
