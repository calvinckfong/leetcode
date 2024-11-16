// 203. Remove Linked List Elements
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *last = 0;
        ListNode *node = head;

        while (node) {
            if (node->val != val) {
                last = node;
                node = node->next;
            } else if (last!=0) {
                last->next = node->next;
                node = node->next;
            } else {
                node = head = head->next;
            }
        }
        return head;
    }
};
