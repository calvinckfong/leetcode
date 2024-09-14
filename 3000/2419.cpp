// 2419. Longest Subarray With Maximum Bitwise AND
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longestSubarrayLen=0, maxVal=0, len=0;

        for (int val: nums) {
            if (val > maxVal) {
                maxVal = val;
                longestSubarrayLen = len = 0;
            }
            len = (maxVal == val) ? (len+1) : 0;
            longestSubarrayLen = max(longestSubarrayLen, len);
        }

        return longestSubarrayLen;
    }
};
