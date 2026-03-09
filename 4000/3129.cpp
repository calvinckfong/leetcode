// 3129. Find All Possible Stable Binary Arrays I
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero+1, 
            vector<vector<int>>(one+1, 
                vector<int>(2)));
        const int MOD = 1e9 + 7;
        for (int i=0; i<=min(zero, limit); i++) dp[i][0][0] = 1;
        for (int i=0; i<=min(one, limit); i++) dp[0][i][1] = 1;

        for (int i=1; i<=zero; i++) {
            for (int j=1; j<=one; j++) {
                long tmp; 
                tmp = dp[i-1][j][0] + dp[i-1][j][1];
                if (i>limit) tmp -= dp[i-limit-1][j][1];
                dp[i][j][0] = (tmp + MOD)%MOD;
                
                tmp = dp[i][j-1][1] + dp[i][j-1][0];
                if (j>limit) tmp -= dp[i][j-limit-1][0];
                dp[i][j][1] = (tmp + MOD)%MOD;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
