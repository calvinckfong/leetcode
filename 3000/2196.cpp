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
// 2196. Create Binary Tree From Descriptions
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root = nullptr;
        unordered_map<int, TreeNode*> nodeMap;
        set<int> nodeSet;
        for (vector<int> d: descriptions) {
            nodeSet.insert(d[0]);
            auto parent = nodeMap.find(d[0]);
            auto child = nodeMap.find(d[1]);
            if (parent==nodeMap.end())
                nodeMap[d[0]] = new TreeNode(d[0]);
            if (child==nodeMap.end())
                nodeMap[d[1]] = new TreeNode(d[1]);
            
            if (d[2])   nodeMap[d[0]]->left = nodeMap[d[1]];
            else nodeMap[d[0]]->right = nodeMap[d[1]];
        }

        // find root
        for (vector<int> d: descriptions)
            nodeSet.erase(d[1]);
        
        return nodeMap[*(nodeSet.begin())];
    }
};
