// 2140. Solving Questions With Brainpower
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1);
        for (int i=n-1; i>=0; i--) {
            int pts = questions[i][0];
            int jump = questions[i][1];
            dp[i] = max(pts + dp[min(jump+i+1, n)], dp[i+1]);
        }
        return dp[0];
    }
};
