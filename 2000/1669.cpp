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
// 1669. Merge In Between Linked Lists
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *p1=list1, *p2=list1;
        while (--a) p1 = p1->next;
        while (b--) p2 = p2->next;
        p1->next = list2;
        while (list2->next) list2 = list2->next;
        list2->next = p2->next;
        return list1;
    }
};
