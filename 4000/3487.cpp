// 3487. Maximum Unique Subarray Sum After Deletion
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res = 0;
        sort(nums.rbegin(), nums.rend());

        if (nums[0] <= 0) return nums[0];
        int last = res = nums[0];

        for (int i=0; i<nums.size(); i++) {
            if (nums[i]<=0) break;
            if (nums[i] != last) {
                last = nums[i];
                res += last;
            }
        }
        return res;
    }
};
