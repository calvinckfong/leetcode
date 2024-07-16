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
// 2096. Step-By-Step Directions From a Binary Tree Node to Another
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // find the path from startValue to root and endValue to root
        string s1="", s2="";
        dfs(root, startValue, s1);
        dfs(root, destValue, s2);

        // remove common path
        while (s1.size() && s2.size() && s1.back()==s2.back()) {
            s1.pop_back();
            s2.pop_back();
        }
        
        // concat in correct order
        reverse(s2.begin(), s2.end());
        return string(s1.size(), 'U') + s2;
    }

    bool dfs(TreeNode* node, const int target, string& s) {
        if (node==NULL) return false;
        if (node->val == target) return true;
        
        if (dfs(node->left, target, s)) {
            s+="L";
            return true;
        }
        if (dfs(node->right, target, s)) {
            s+="R";
            return true;
        }
        return false;
    }
};
