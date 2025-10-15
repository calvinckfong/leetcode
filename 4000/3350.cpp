// 3350. Adjacent Increasing Subarrays Detection II
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int len=1, prev_len=0, res=0;
        for (int i=1; i<n; i++) {
            if (nums[i] > nums[i-1]) {
                len++;
            } else {
                prev_len = len;
                len = 1;
            }
            res = max(res, min(prev_len, len));
            res = max(res, len/2);
        }
        return res;
    }
};
