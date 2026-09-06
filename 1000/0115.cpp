// 115. Distinct Subsequences
class Solution {
public:
    int numDistinct(string s, string t) {
        int m =s.size(), n = t.size();
        if (m<n) return 0;

        vector<unsigned long long> dp(n+1);
        dp[n] = 1;

        for (int i=m-1; i>=0; i--) {
            auto cs = s[i];
            for (int j=0; j<n; j++) {
                auto ct= t[j];
                if (cs == ct) dp[j] += dp[j+1];
            }
        }
        return dp[0];
    }
};
