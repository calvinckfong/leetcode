// 3217. Delete Nodes From Linked List Present in Array
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int max_num = *max_element(nums.begin(), nums.end());
        vector<bool> set(max_num+1, false);
        for (int x: nums)
            set[x]= true;
        
        ListNode* root = new ListNode;
        ListNode* curr = root;
        int n = set.size();
        while (head!=nullptr) {
            if (head->val>=n || set[head->val]==false) {
                curr->next = head;
                curr = curr->next;
            }
            head = head->next;
        }
        curr->next = nullptr;
        return root->next;
    }
};
