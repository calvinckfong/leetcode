// 1290. Convert Binary Number in a Linked List to Integer
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while (head) {
            res = res*2 + head->val;
            head = head->next;
        }
        return res;
    }
};
