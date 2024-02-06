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
// 23. Merge k Sorted Lists
class Solution {
public:
    ListNode* MergeList(ListNode* l1, ListNode* l2)
    {
        ListNode* ret = new ListNode, *p=ret;

        while (l1 || l2)
        {
            if (l1 && l2)
            {
                if (l1->val < l2->val)
                {
                    p->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    p->next = l2;
                    l2 = l2->next;
                }
            }
            else if (l1)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else if (l2)
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        return ret->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = new ListNode(-1e5);

        for (int i=0; i<lists.size(); i++)
        {
            if (lists[i] == nullptr) continue;
            ret = MergeList(ret, lists[i]);
        }

        return ret->next;
    }
};
