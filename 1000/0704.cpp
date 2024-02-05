// 704. Binary Search
class Solution {
public:
    // 704. Binary Search
    int search(vector<int>& nums, int target) {
        int l=0, h=nums.size(), m;

        while (h>l)
        {
            m = l + (h-l)/2;
            if (nums[m] > target)
                h = m;
            else if (nums[m] < target)
                l = m+1;
            else 
                return m;
        }
        return -1;
    }
};
