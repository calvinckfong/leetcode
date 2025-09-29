// 1039. Minimum Score Triangulation of Polygon
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len=3; len<=n; len++) {
            for (int i=0; i+len-1<n; i++) {
                int j=i+len-1;
                dp[i][j] = INT_MAX;
                int tmp = values[i]*values[j];
                for (int k=i+1; k<j; k++) {
                    int score = dp[i][k] + dp[k][j] + tmp*values[k];
                    dp[i][j] = min(dp[i][j], score);
                }
            }
        }
        return dp[0][n-1];
    }
};
