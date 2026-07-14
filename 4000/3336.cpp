// 3336. Find the Number of Subsequences With Equal GCD
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int m = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> dp(m+1, vector<int>(m+1));
        dp[0][0] = 1;

        for (int& x: nums) {
            vector<vector<int>> ndp(m+1, vector<int>(m+1));
            for (int i=0; i<=m; i++) {
                int div1 = gcd(i, x);
                for (int j=0; j<=m; j++) {
                    int val = dp[i][j];
                    if (val==0) continue;

                    int div2 = gcd(j, x);
                    ndp[i][j] = (ndp[i][j] + val) % MOD;
                    ndp[div1][j] = (ndp[div1][j] + val) % MOD;
                    ndp[i][div2] = (ndp[i][div2] + val) % MOD;
                }
            }
            dp.swap(ndp);
        }

        int res = 0;
        for (int i=1; i<=m; i++) {
            res = (res + dp[i][i]) % MOD;
        }
        return res;
    }
};
