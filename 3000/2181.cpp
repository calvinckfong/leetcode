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
// 2181. Merge Nodes in Between Zeros
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *dummy = new ListNode, *result = dummy;
    
        int sum = 0;
        head = head->next;
        while (head) {
            if (head->val == 0) {
                dummy->next = new ListNode(sum);
                dummy = dummy->next;
                sum = 0;
            } else {
                sum += head->val;
            }
            head = head->next;
        }

        return result->next;
    }
};
