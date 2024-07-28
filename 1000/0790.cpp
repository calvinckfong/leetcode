// 790. Domino and Tromino Tiling
class Solution {
public:
    int numTilings(int n) {
        dp = vector<vector<long>>(n+2, vector<long>(2, -1));
        return solve(0, n, false);
    }

private:
    const long MOD = 1e9+7;
    vector<vector<long>> dp;
    long getDP(int i, int n, bool j) {
        long result;
        if (dp[i][j] == -1) {
            result = solve(i, n, j);
            dp[i][j] = result;
        } else {
            result = dp[i][j];
        }
        return result;
    }

    long solve(int i, int n, bool previousGap) {
        if (i>n)    return 0;  // over-run
        if (i==n)   return !previousGap;

        long d1, d2, d3, d4;
        d1 = getDP(i+1, n, false);
        if (previousGap) {
            int d2 = getDP(i+1, n, true);
            return (d1 + d2) % MOD;
        }
        d3 = getDP(i+2, n, false);
        d4 = getDP(i+2, n, true);
        return (d1 + d3 + 2l*d4) % MOD;
    }
};
