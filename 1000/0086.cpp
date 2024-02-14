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
// 86. Partition List
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* hi = new ListNode, *ph=hi;
        ListNode* lo = new ListNode, *pl=lo;
        
        while (head)
        {
            if (head->val<x)
            {
                pl->next = head;
                pl = pl->next;
            }
            else
            {
                ph->next = head;
                ph = ph->next;
            }
            head = head->next;
        }
        ph->next = nullptr;
        pl->next = hi->next;
        return lo->next;
    }
};
