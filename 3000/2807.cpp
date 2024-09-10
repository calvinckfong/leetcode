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
// 2807. Insert Greatest Common Divisors in Linked List
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *last=head, *node=head->next;;
        
        while (node) {
            ListNode* newNode = new ListNode(gcd(node->val, last->val), node);
            last->next = newNode;
            last = node;
            node = node->next;
        }
        return head;
    }
};
