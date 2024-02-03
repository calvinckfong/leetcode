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
// 61. Rotate List
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k==0 || !head) return head;
        int n=1;
        ListNode* ret = head;
        while (ret->next)
        {
            n++;
            ret = ret->next;
        }
        ret->next = head;  // form a ring
        
        ret = head;
        for (int i=0; i<n-(k%n)-1 ; i++)
        {
            ret = ret->next;
        }
        head = ret->next;
        ret->next = 0;  // break the ring

        return head;
    }
};
