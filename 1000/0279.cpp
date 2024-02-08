// 279. Perfect Squares
class Solution {
public:
    vector<int> dp;

    int numSquares(int n) {
        dp = vector<int>(n+1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i=2; i<n+1; i++)
        {
            dp[i] = INT_MAX;
            for (int j=1; j*j<=i; j++)
                dp[i] = min(dp[i], dp[i-j*j]+1);
        }

        return dp[n];
    }
};
