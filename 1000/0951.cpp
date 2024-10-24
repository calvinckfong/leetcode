// 951. Flip Equivalent Binary Trees
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val)  return false;

        bool case1 = flipEquiv(root1->left, root2->right) && 
                     flipEquiv(root1->right, root2->left);
        bool case2 = flipEquiv(root1->left, root2->left) && 
                     flipEquiv(root1->right, root2->right);

        return case1 || case2;
    }
};
