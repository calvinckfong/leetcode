// 837. New 21 Game
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n+1);
        dp[0] = 1.0;
        double s = (k>0)?1.0:0.0;
        for (int i=1; i<=n; i++) {
            dp[i] = s /maxPts;
            if (i<k)    s += dp[i];
            int diff = i-maxPts;
            if (diff>=0 && diff<k) s -= dp[diff];
        }
        return accumulate(dp.begin()+k, dp.end(), 0.0);
    }
};
