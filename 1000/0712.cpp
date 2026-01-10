// 712. Minimum ASCII Delete Sum for Two Strings
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int sum = 0;
        vector<int> dp(n2+1, 0);

        for (char& c: s1) sum+=c;
        for (char& c: s2) sum+=c;

        for (int i=0; i<n1; i++) {
            int prev = 0;
            for (int j=0; j<n2; j++) {
                int tmp = dp[j+1];

                if (s1[i] == s2[j]) {
                    dp[j+1] = prev + s1[i];
                } else {
                    dp[j+1] = max(dp[j+1], dp[j]);
                }

                prev = tmp;
            }
        }
        return sum - 2* dp[n2];
    }
};
