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
// 143. Reorder List
class Solution {
public:
    void reorderList(ListNode* head) {
        // Find mid-point
        ListNode *fast=head, *slow=head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
 
        // reverse right part
        ListNode* ptr = slow;
        stack<int> s;
        while (ptr)
        {
            s.push(ptr->val);
            ptr = ptr->next;
        }
        
        // merge
        ptr = head;
        while (!s.empty())
        {
            if (ptr == slow)
            {
                ptr->next = nullptr;
                break;
            }
            else if (s.size()==1) {
                ptr->next = new ListNode(s.top());
                s.pop();
            }
            else
            {
                ptr->next = new ListNode(s.top(), ptr->next);
                s.pop();
                ptr = ptr->next->next;
            }
        }
    }
};
