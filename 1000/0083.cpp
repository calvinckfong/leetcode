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
 // 83. Remove Duplicates from Sorted List
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        if (!p || !p->next) return head;

        while (p->next)
        {
            if (p->val == p->next->val)
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }

        return head;
    }
};
