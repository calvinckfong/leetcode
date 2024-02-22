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
// 234. Palindrome Linked List
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // fast termination
        if (!head || !head->next) return true;

        ListNode *slow=head, *fast=head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next;
        
        // reverse 2nd half
        ListNode *prev=nullptr, *curr=slow, *next;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //ListNode *p1=head, *p2=prev;
        while (prev)
        {
            if (head->val != prev->val) return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};
