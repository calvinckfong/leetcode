// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int l, r, result=1;
        // increasing
        for (l=0, r=1; r<nums.size(); r++) {
            if (nums[r]<=nums[r-1]) {
                result = max(result, r-l);
                l=r;
            }
        }
        result = max(result, r-l);

        // decreasing
        for (l=0, r=1; r<nums.size(); r++) {
            if (nums[r]>=nums[r-1]) {
                result = max(result, r-l);
                l=r;
            }
        }
        result = max(result, r-l);

        return result;
    }
};
