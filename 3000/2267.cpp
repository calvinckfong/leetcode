// 2267. Check if There Is a Valid Parentheses String Path
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int pathLen = m+n-1;
        if (pathLen&1) return false;
        if (grid[0][0]!='(' || grid[n-1][m-1]!=')') return false;

        vector<vector<bitset<201>>> dp(n, vector<bitset<201>>(m));
        dp[0][0].set(1);

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int change = (grid[i][j]=='(');

                if (i>0) {
                    if (change)
                        dp[i][j] |= dp[i-1][j]<<1;
                    else
                        dp[i][j] |= dp[i-1][j]>>1;
                }

                if (j>0) {
                    if (change)
                        dp[i][j] |= dp[i][j-1]<<1;
                    else
                        dp[i][j] |= dp[i][j-1]>>1;
                }
            }
        }

        return dp[n-1][m-1].test(0);
    }
};
