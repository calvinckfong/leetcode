// 940. Distinct Subsequences II
class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<int> dp(n+1);
        dp[0] = 1;
        int last[26];
        for (int i=0; i<26; i++) last[i] = -1;

        for (int i=0; i<n; i++) {
            int c = s[i] - 'a';
            dp[i+1] = dp[i] * 2 % MOD;
            if (last[c]>=0) dp[i+1] -= dp[last[c]];
            dp[i+1] %= MOD;
            last[c] = i; 
        }
        int res = (dp[n] - 1);
        return (res>=0) ? res : res + MOD;
    }
};
