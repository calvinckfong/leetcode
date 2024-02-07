/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 160. Intersection of Two Linked Lists
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        
        while (pA!=pB)
        {
            // loop back to head when at the tail
            pA = (pA==nullptr)?headA:pA->next;
            pB = (pB==nullptr)?headB:pB->next;
        }

        return pA;
    }
};
