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
// 1171. Remove Zero Sum Consecutive Nodes from Linked List
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Linked list to array
        vector<int> arr;
        while (head)
        {
            arr.push_back(head->val);
            head = head->next;
        }

        // brute-force remove sub array with zero sums
        for (int i=0; i<arr.size(); i++)
        {
            int sum = 0;
            for (int j=i; j<arr.size(); j++)
            {
                sum += arr[j];
                if (sum==0) {
                    for (int k=i; k<j+1; k++) arr[k]=0;
                    break;
                }
            }
        }

        // Array to linked list
        ListNode dummy(0), *p=&dummy;
        for (int i=0; i<arr.size(); i++)
        {
            if (arr[i]!=0) {
                p->next = new ListNode(arr[i]);
                p = p->next;
            }
        }

        return dummy.next;
    }
};
