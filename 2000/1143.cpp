// 1143. Longest Common Subsequence
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1 == text2) return text1.size();

        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> DP(m+1, vector<int>(n+1, 0));

        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (text1[i-1] == text2[j-1])
                    DP[i][j] = DP[i-1][j-1] + 1;
                else
                    DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
        return DP[m][n];
    }
};
