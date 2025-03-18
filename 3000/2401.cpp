// 2401. Longest Nice Subarray
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0, r=0, n=nums.size();
        int flag = 0, result = 0;

        while (r<n) {
            while ((flag&nums[r]) != 0) {
                flag ^= nums[l++];
            }

            flag |= nums[r++];
            result = max(result, r-l);
        }
        return result;
    }
};
