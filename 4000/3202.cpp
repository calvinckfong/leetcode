// 3202. Find the Maximum Length of Valid Subsequence II
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int res = 0;
        vector<vector<int>> dp(k, vector<int>(k, 0));
        for (int num: nums) {
            num %= k;
            for (int i=0; i<k; i++) {
                int l = dp[i][num] = dp[num][i] + 1;
                res = max(res, l);
            }
        }
        return res;
    }
};
