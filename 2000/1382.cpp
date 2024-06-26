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
// 1382. Balance a Binary Search Tree
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> array;
        bst2array(root, array);
        sort(array.begin(), array.end());

        return build(array, 0, array.size());
    }
private:
    void bst2array(TreeNode* root, vector<int>& array) {
        if (root) {
            array.push_back(root->val);
            bst2array(root->left, array);
            bst2array(root->right, array);
        }
    }

    TreeNode* build(vector<int>& array, int l, int r) {
        if (r<=l) return nullptr;
        int mid = (r+l-1)/2;
        TreeNode* root = new TreeNode(array[mid]);
        root->left  = build(array, l, mid);
        root->right = build(array, mid+1, r);
        return root;
    }
};
