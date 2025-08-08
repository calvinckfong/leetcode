// 808. Soup Servings
class Solution {
public:
    double soupServings(int n) {
        if (n>=4800) return 1.0;

        int m = ceil(n / 25.0);
        
        dp[0][0] = 0.5;
        for (int i=1; i<=m; i++) {
            dp[0][i] = 1;
            dp[i][0] = 0;
            for (int j=1; j<=i; j++) {
                dp[j][i] = solve(j, i);
                dp[i][j] = solve(i, j);
            }
            if (dp[i][i] > 1-1e-5) return 1;
        }
        return dp[m][m];
    }

private:
    double dp[201][201] = {-1.0f};
    double solve(int i, int j) {
        return (dp[max(0, i-4)][j] + 
            dp[max(0, i-3)][j-1] +
            dp[max(0, i-2)][max(0, j-2)] +
            dp[i-1][max(0, j-3)] )/4;
    }
};
