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
// 3217. Delete Nodes From Linked List Present in Array
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for (int n : nums)  s.insert(n);

        ListNode* dummy = new ListNode, *node = dummy;
        while (head) {
            if (!s.contains(head->val)) {
                node->next = new ListNode(head->val);
                node = node->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};
