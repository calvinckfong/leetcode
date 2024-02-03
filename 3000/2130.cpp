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
// 2130. Maximum Twin Sum of a Linked List
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        ListNode* p = head;
        int n=0;
        while (p)
        {
            n++;
            nums.push_back(p->val);
            p = p->next;
        }

        int maxSum = 0;
        for (int i=0; i<n/2; i++)
        {
            maxSum = max(maxSum, nums[i]+nums[n-i-1]);
        }
        return maxSum;
    }
};
