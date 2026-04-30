// 3742. Maximum Path Score in a Grid

using vi = vector<int>;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vi>> dp(m, vector<vi>(n, vi(k+1, INT_MIN)));
        dp[0][0][0] = 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                for (int x=0; x<=k; x++) {
                    if (dp[i][j][x] == INT_MIN) continue;
                    int val, cost;
                    if (i+1<m) {
                        val = grid[i+1][j];
                        cost = (val!=0);
                        if (x+cost<=k) {
                            dp[i+1][j][x+cost] = max(dp[i+1][j][x+cost],
                                dp[i][j][x]+val);
                        }
                    }
                    if (j+1<n) {
                        val = grid[i][j+1];
                        cost = (val!=0);
                        if (x+cost<=k) {
                            dp[i][j+1][x+cost] = max(dp[i][j+1][x+cost],
                                dp[i][j][x]+val);
                        }
                    }
                }
            }
        }

        int res = *max_element(dp[m-1][n-1].begin(), dp[m-1][n-1].end());
        return (res<0)?-1:res;
    }
};
