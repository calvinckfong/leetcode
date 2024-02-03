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
// 21. Merge Two Sorted Lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1, *p2 = list2;
        ListNode *ret=new ListNode, *r=ret;

        while (p1 || p2)
        {
            if (p1 && p2)
            {
                if (p1->val < p2->val)
                {
                    r->next = new ListNode(p1->val);
                    p1 = p1->next;
                } else {
                    r->next = new ListNode(p2->val);
                    p2 = p2->next;
                }
            }
            else if (p1)
            {               
                r->next = p1;   
                break;
            }
            else
            {
                r->next = p2;
                break;
            }
            if (!ret)   ret = r;
            r = r->next;
        }
        return ret->next;
    }
};
