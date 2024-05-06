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
// 2487. Remove Nodes From Linked List
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* node = head;
        stack<ListNode*> st;
        while (node) {
            while (!st.empty() && st.top()->val < node->val) {
                st.pop();
            }
            st.push(node);
            node = node->next;
        }

        ListNode* next = nullptr;
        while (!st.empty()) {
            node = st.top();
            st.pop();
            node->next = next;
            next = node;
        }
        
        return node;
    }
};
