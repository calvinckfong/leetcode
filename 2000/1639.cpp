// 1639. Number of Ways to Form a Target String Given a Dictionary
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int mod = 1e9 + 7;
        int wn = words[0].size(), tn = target.size();
    
        vector<vector<int>> freq(wn, vector<int>(26, 0));
        for (int i=0; i<words.size(); i++) {
            string w = words[i];
            for (int j=0; j<wn; j++) {
                freq[j][w[j]-'a']++;
            }
        }

        vector<vector<long>> dp(wn+1, vector<long>(tn+1, 0));
        for (int i=0; i<wn; i++) {
            dp[i][0] = 1;
        }

        for (int i=1; i<=wn; i++) {
            for (int tidx=1; tidx <= tn; tidx++) {
                dp[i][tidx] = dp[i-1][tidx];

                int pos = target[tidx-1] - 'a';
                dp[i][tidx] += (freq[i-1][pos] * dp[i-1][tidx-1]) % mod;
                dp[i][tidx] %= mod;
            }
        }

        return dp[wn][tn];
    }
};
