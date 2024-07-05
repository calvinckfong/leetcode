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
// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //vector<int> result = {INT_MAX, 0};
        int minD = INT_MAX;
        int firstCritical = -1, lastCritical = -1;
        int last_last_val = head->val;  head = head->next;
        int last_val = head->val; head = head->next;
        int cnt = 1, criticalCnt=0;
        while (head) {
            cnt ++;
            if ((last_val>last_last_val && last_val>head->val) ||
                (last_val<last_last_val && last_val<head->val)) {

                if (criticalCnt==0) firstCritical = cnt;
                if (criticalCnt>0) minD = min(minD, cnt-lastCritical);
                lastCritical = cnt;
                criticalCnt++;
                
            }
            last_last_val = last_val;
            last_val = head->val;
            head = head->next;
        }
        if (criticalCnt<=1) return {-1, -1};
        return {minD, lastCritical - firstCritical};
    }
};
