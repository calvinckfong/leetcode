/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
// 1367. Linked List in Binary Tree
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            if (match(head, node))
                return true;

            if (node->left)     q.push(node->left);
            if (node->right)    q.push(node->right);
        }
        return false;
    }

private:
    bool match(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;
        if (root == nullptr) return false;

        if (head->val != root->val) return false;

        return  match(head->next, root->left) ||
                match(head->next, root->right);    
    }
};