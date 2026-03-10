// 3130. Find All Possible Stable Binary Arrays II
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9+7;
        vector<vector<vector<int>>> dp(zero+1,
            vector<vector<int>>(one+1, 
                vector<int>(2)));
        for (int i=0; i<=zero; i++) {
            for (int j=0; j<=one; j++) {
                for (int lastBit=0; lastBit<=1; lastBit++) {
                    long curr = 0;
                    if (i==0) {
                        curr = !(lastBit==0 || j>limit);
                    } else if (j==0) {
                        curr = !(lastBit==1 || i>limit);
                    } else if (lastBit==0) {
                        curr = dp[i-1][j][0] + dp[i-1][j][1];
                        if (i>limit) curr -= dp[i-limit-1][j][1];
                    } else {
                        curr = dp[i][j-1][0] + dp[i][j-1][1];
                        if (j>limit) curr -= dp[i][j-limit-1][0];
                    }
                    curr = (curr+MOD)%MOD; 
                    dp[i][j][lastBit] = curr;
                }
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
