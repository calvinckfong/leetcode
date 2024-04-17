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
// 988. Smallest String Starting From Leaf
class Solution {
public:
    void minString(TreeNode* root, string curr, string& minS) {
        curr = char('a'+root->val)+curr;

        if (!root->left && !root->right) {
            minS = min(curr, minS);
            return;
        }

        if (root->left) {
            minString(root->left, curr, minS);
        }
        if (root->right) {
            minString(root->right, curr, minS);
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";

        string curr="", result="";
        result += char('z'+1);
        minString(root, curr, result);
        return result;
    }
};
