// 2419. Longest Subarray With Maximum Bitwise AND
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res=0, maxVal=0, len=0;

        for (int& val: nums) {
            if (val > maxVal) {
                maxVal = val;
                res = len = 0;
            }
            len = (maxVal == val) ? (len+1) : 0;
            res = max(res, len);
        }

        return res;
    }
};
