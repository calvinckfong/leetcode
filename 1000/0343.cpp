// 343. Integer Break
class Solution {
public:
    vector<int> dp;
    int solve(int n, int numCnt)
    {
        if (numCnt && n<=3) return n;
        else if (numCnt==0 && n<=2) return 1;

        int prod, maxVal = 0;
        for (int i=n-(numCnt==0); i>=2; i--)
        {
            if (dp[n-i]==0)
                dp[n-i] = solve(n-i, numCnt+1);

            prod = i * dp[n-i];
            maxVal = max(maxVal, prod);
        }
        return maxVal;
    }

    int integerBreak(int n) {
        dp = vector<int>(n+1, 0);
        return solve(n, 0);
    }
};
