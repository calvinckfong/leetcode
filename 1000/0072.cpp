// 72. Edit Distance
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();
        vector<vector<int>> DP(m+1, vector<int>(n+1, 0));
        for (int i=0; i<=m; i++) DP[i][0] = i;
        for (int i=0; i<=n; i++) DP[0][i] = i;

        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (word1[i-1]==word2[j-1]) {
                    DP[i][j] = DP[i-1][j-1];
                } else {
                    DP[i][j] = min(DP[i-1][j-1], min(DP[i-1][j], DP[i][j-1])) + 1;
                }
            }
        }
        return DP[m][n];
    }
};
