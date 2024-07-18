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
// 1530. Number of Good Leaf Nodes Pairs
class Solution {
public:
    int count;
    int countPairs(TreeNode* root, int distance) {
        count = 0;
        dfs(root, distance);
        return count;
    }

private:
    vector<int> dfs(TreeNode* node, int distance) {
        vector<int> result = {}; // storing the distance to its leaf nodes
        if (node==nullptr) return result;

        // check its child nodes
        vector<int> leftRes = dfs(node->left, distance);
        vector<int> rightRes = dfs(node->right, distance);

        // Add 1 and return if it is a leaf node
        if (leftRes.empty() && rightRes.empty()) {
            result.push_back(1);
            return result;
        }

        // check the good pair between left and right branches
        for (int i=0; i<leftRes.size(); i++) {
            int l = leftRes[i];
            for (int j=0; j<rightRes.size(); j++) {
                int r = rightRes[j];
                count += (l+r <= distance);
            }
        }

        // increase the collected leaf node distances by 1
        // and return to the parent
        for (int i=0; i<leftRes.size(); i++)
            result.push_back(leftRes[i]+1);
        
        for (int i=0; i<rightRes.size(); i++)
            result.push_back(rightRes[i]+1);

        return result;
    }
};
