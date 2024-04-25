// 2370. Longest Ideal Subsequence
class Solution {
public:
    int longestIdealString(string s, int k) {
        if (s.size()==0) return 0;
        
        int dp[27] = {0}; // A to Z + 1
        for (int i=s.size()-1; i>=0; i--) {
            int idx = s[i]-'a';
            int l = max(idx-k, 0);
            int r = min(idx+k, 26);
            int maxl = -1;

            for (int j=l; j<=r; j++)
                maxl = max(maxl, dp[j]);
            
            dp[idx] = maxl+1;
        }

        int result = 0;
        for (int i=0; i<27; i++) {
            result = max(result, dp[i]);
        }

        return result;
    }
};
