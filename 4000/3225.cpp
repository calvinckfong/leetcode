// 3225. Maximum Score From Grid Operations

using vll = std::vector<long long>;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (n == 1) return 0;

        vector<vector<vll>> dp(n, vector<vll>(n + 1, vll(n + 1, 0)));
        vector<vll> prevMax(n + 1, vll(n + 1, 0));
        vector<vll> prevSuffixMax(n + 1, vll(n + 1, 0));
        vector<vll> colSum(n, vll(n + 1, 0));

        for (int i=0; i<n; i++) {
            for (int j=1; j<=n; j++) {
                colSum[i][j] = colSum[i][j-1] + grid[j-1][i];
            }
        }

        long long score, penalty;
        for (int i=1; i<n; i++) {
            for (int j=0; j<= n; j++) {
                for (int k=0; k<=n; k++) {
                    if (j<=k) {
                        score = colSum[i][k] - colSum[i][j];
                        dp[i][j][k] = std::max(dp[i][j][k],
                                     prevSuffixMax[k][0] + score);
                    } else {
                        score = colSum[i-1][j] - colSum[i-1][k];
                        dp[i][j][k] = std::max(
                            {dp[i][j][k], prevSuffixMax[k][j],
                             prevMax[k][j] + score});
                    }
                }
            }

            for (int j = 0; j <= n; j++) {
                prevMax[j][0] = dp[i][j][0];
                for (int k=1; k<=n; k++) {
                    penalty = (k>j) ? (colSum[i][k] - colSum[i][j]) : 0;
                    prevMax[j][k] = std::max(prevMax[j][k-1],
                                 dp[i][j][k] - penalty);
                }

                prevSuffixMax[j][n] = dp[i][j][n];
                for (int k = n-1; k >= 0; k--) {
                    prevSuffixMax[j][k] = std::max(
                        prevSuffixMax[j][k + 1], dp[i][j][k]);
                }
            }
        }

        long long ans = 0;
        for (int i=0; i<=n; i++) {
            ans = std::max({ans, dp[n-1][n][i], dp[n-1][0][i]});
        }

        return ans;
    }
};
