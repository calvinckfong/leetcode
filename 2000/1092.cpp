// 1092. Shortest Common Supersequence 
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1));

        for (int i=n1-1; i>=0; i--) {
            for (int j=n2-1; j>=0; j--) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        string result="";
        int i=0, j=0;
        while (i<n1 && j<n2) {
            if (str1[i] == str2[j]) {
                result += str1[i++];
                j++;
            } else if (dp[i+1][j] >= dp[i][j+1]) {
                result += str1[i++];
            } else {
                result += str2[j++];
            }
        }

        while (i<n1) {
            result += str1[i++];
        }

        while (j<n2) {
            result += str2[j++];
        }

        return result;
    }
};
