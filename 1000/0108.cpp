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
// 108. Convert Sorted Array to Binary Search Tree
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n==0)   return nullptr;
        else if (n==1) return new TreeNode(nums[0]);
        
        int mid = n/2;
        TreeNode *head = new TreeNode(nums[mid]);
        auto lstart = nums.begin();
        auto lend = nums.begin() + mid;
        auto rstart = nums.begin() + mid + 1;
        auto rend = nums.end();
        vector<int> lvec = vector<int>(lstart, lend);
        vector<int> rvec = vector<int>(rstart, rend);
        head->left = sortedArrayToBST(lvec);
        head->right = sortedArrayToBST(rvec);
        return head;
    }
};
