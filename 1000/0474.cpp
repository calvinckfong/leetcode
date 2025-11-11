// 474. Ones and Zeroes
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        int numZeros, numOnes;
        for (auto& s: strs) {
            numZeros = numOnes = 0;
            for (auto& c: s) {
                numZeros+=(c=='0');
                numOnes+=(c=='1');
            }
        
            for (int i=m; i>=numZeros; i--) {
                for (int j=n; j>=numOnes; j--) {
                    dp[i][j] = max(dp[i][j], dp[i-numZeros][j-numOnes]+1);
                }
            }
        }

        return dp[m][n];
    }
};
