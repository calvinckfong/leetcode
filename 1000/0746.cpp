// 746. Min Cost Climbing Stairs
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size(), i=n-1;
        vector<int> dp(n+2, 0);
        while (i>=0)
        {
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
            i--;
        }
        return min(dp[0], dp[1]);
    }
};
