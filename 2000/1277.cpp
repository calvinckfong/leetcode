// 1277. Count Square Submatrices with All Ones
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        int result = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j]) {
                    dp[i+1][j+1] = 1 + min({dp[i][j], dp[i+1][j], dp[i][j+1]});
                    result += dp[i+1][j+1];
                }
            }
        }
        return result;
    }
};
