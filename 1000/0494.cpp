// 494. Target Sum
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target)>total) return 0;

        vector<int> dp(2*total+1, 0);
        dp[total + nums[0]] ++;
        dp[total - nums[0]] ++;

        for (int i=1; i<n; i++) {
            vector<int> next(2*total+1, 0);
            for (int j=0; j<2*total+1; j++) {
                if (dp[j]>0) {
                    next[j+nums[i]] += dp[j];
                    next[j-nums[i]] += dp[j];
                }
            }
            dp = next;
        }
        return dp[target+total];
    }
};
