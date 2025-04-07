// 416. Partition Equal Subset Sum
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total%2) return false;
        int target = total/2;
        vector<bool> dp(target+1);
        dp[0] = true;
        for (auto& num: nums) {
            for (int curr=target; curr>=num; --curr) {
                dp[curr] = dp[curr] | dp[curr-num];
                if (dp[target]) return true;
            }
        }
        return dp[target];
    }
};
