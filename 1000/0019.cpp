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
// 19. Remove Nth Node From End of List
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1=head, *p2=head;
        while (n--)
            p1 = p1->next;
        
        ListNode *newList = new ListNode, *np = newList;
        while (p1)
        {
            np->next = new ListNode(p2->val);
            np = np->next;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (p2)
            np->next = p2->next;

        return newList->next;
    }
};
