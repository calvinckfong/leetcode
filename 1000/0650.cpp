// 650. 2 Keys Keyboard
class Solution {
public:
    int minSteps(int n) {
        const int maxStep = 1000;
        vector<int> dp(n+1, maxStep);
        dp[1] = 0;
        for (int i=2; i<=n ; i++) {
            for (int j=1; j<=i/2; j++) {
                if (i%j==0)
                    dp[i] = min(dp[i], dp[j] + i/j);
            }
        }

        return dp[n];
    }
};
