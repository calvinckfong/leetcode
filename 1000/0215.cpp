// 215. Kth Largest Element in an Array
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i=0; i<nums.size(); i++)
            pq.push(nums[i]);

        int res;
        for (int i=0; i<k-1; i++)
            pq.pop();
        return pq.top();
    }
};
