// 1493. Longest Subarray of 1's After Deleting One Element
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeros=0, l=0, res=0;
        for (int r=0; r<nums.size(); r++) {
            zeros += (nums[r]==0);
            while (zeros>1) {
                zeros -= (nums[l]==0);
                l++;
            }
            res = max(res, r-l);
        }
        return res;
    }
};
