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
// 101. Symmetric Tree
class Solution {
public:
    bool CheckSymmetric(TreeNode* left, TreeNode* right)
    {
        if (!left && !right) return true;
        if (left && right)
        {
            if (left->val == right->val)
            {
                return (CheckSymmetric(left->left, right->right) &&
                    CheckSymmetric(left->right, right->left));
            }
            return false;
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)  return true;
        return CheckSymmetric(root->left, root->right);
        // TreeNode* l = root;
        // TreeNode* r = root;
        // while (true)
        // {
        //     l = NextLeft(root);
        //     l = NextRight(root);
        //     if (!l && !r) continue;
        //     if (l && r && l->val==r->val) continue;
        //     return false;
        // }
        // return ture
    }
};
