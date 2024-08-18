// 264. Ugly Number II
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n==1) return 1;
        vector<int> dp(n);
        dp[0] = 1;

        int idx2=0, idx3=0, idx5=0;
        int l2=2, l3=3, l5=5;

        for (int i=1; i<n; i++) {
            int next = min(l2, min(l3, l5));
            dp[i] = next;

            if (next == l2) {
                l2 = dp[++idx2] * 2;
            } 
            if (next == l3) {
                l3 = dp[++idx3] * 3;
            }
            if (next == l5) {
                l5 = dp[++idx5] * 5;
            }
        }
        return dp[n-1];
    }
};
