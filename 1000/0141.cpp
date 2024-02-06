/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 141. Linked List Cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        if (!slow || !fast || !fast->next)
            return false;

        // Using 2 points moving at different speed
        // there is a cycle in the linked list if they meet
        // otherwise, the fast pointer will arrive the end
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
                return true;
        }
        return false;
    }
};
