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
// 725. Split Linked List in Parts
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        ListNode* node = head;
        while (node) {
            cnt++;
            node = node->next;
        }

        int avg = (cnt + k - 1)/k, idx=0;
        int len = 0;
        vector<ListNode*> result(k);
        node = head;
        while (node) {
            len++;
            if (len == avg) {
                result[idx++] = head;
                head = node->next;
                node->next = nullptr;
                node = head;
                cnt -= len;
                if (--k == 0) break;
                avg = (cnt + k - 1)/k;
                len = 0;
            }
            else
                node = node->next; 
        }
        if (head) {
            result[idx] = head;
        }
        return result;
    }
};
