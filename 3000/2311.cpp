// 2311. Longest Binary Subsequence Less Than or Equal to K
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sum=0, cnt=0;
        int bits = 32 - __builtin_clz(k);
        int n = s.size();
        for (int i=0; i<n; i++) {
            char c = s[n-i-1];
            if (c == '1') {
                if (i<bits && sum + (1<<i) <= k) {
                    sum += (1<<i);
                    cnt++;
                }
            }
            else
            {
                cnt++;
            }
        }
        return cnt;
    }
};
