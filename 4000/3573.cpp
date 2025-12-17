// 3573. Best Time to Buy and Sell Stock V
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<long long>> dp(k+1, vector<long long>(3));
        for (int i=1; i<=k; i++) {
            dp[i][1] = -prices[0];
            dp[i][2] = prices[0];
        }

        for (int i=1; i<n; i++) {
            for (int j=k; j>0; j--) {
                dp[j][0] = max(dp[j][0], 
                        max(dp[j][1]+prices[i], dp[j][2]-prices[i]));
                dp[j][1] = max(dp[j][1], dp[j-1][0] - prices[i]);
                dp[j][2] = max(dp[j][2], dp[j-1][0] + prices[i]);
            }
        }

        return dp[k][0];
    }
};
