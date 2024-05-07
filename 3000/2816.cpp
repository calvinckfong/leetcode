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
// 2816. Double a Number Represented as a Linked List
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<int> st;
        ListNode* node = head;
        while (node) {
            st.push(node->val);
            node = node->next;
        }

        int val, carry = 0;
        ListNode* next = nullptr;
        while (!st.empty()) {
            val = st.top(); st.pop();
            next = new ListNode((val*2+carry)%10, next);
            carry = (val*2)/10;
        }
        if (carry)
            next = new ListNode(1, next);
        return next;
    }
};
