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
// 2. Add Two Numbers
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1=l1, *p2=l2;
        ListNode *res=new ListNode, *p_res=res;
        int sum, carry = 0;
        while (p1 || p2 || carry)
        {
            if (p1 && p2)
            {
                sum = p1->val + p2->val + carry;
                carry = (sum>9)?1:0;
                p_res->val = sum%10;
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1)
            {
                sum = p1->val + carry;
                carry = (sum>9)?1:0;
                p_res->val = sum%10;
                p1 = p1->next;
            }
            else if (p2)
            {
                sum = p2->val + carry;
                carry = (sum>9)?1:0;
                p_res->val = sum%10;
                p2 = p2->next;
            } 
            else
            {
                p_res->val = carry;
                carry = 0;
            }
            
            if (!p1 && !p2 && !carry)
                break;
            
            p_res->next = new ListNode;
            p_res = p_res->next;
        };
        return res;
    } 
};
