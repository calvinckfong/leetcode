// 1411. Number of Ways to Paint N × 3 Grid
class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long a1 = 6, a2 = 6, b;
        for (int i=1; i<n; i++) {
            b = a1*2 + a2*2;
            a1 = (b + a1) % MOD;
            a2 = b % MOD;
        }
        return (int)((a1 + a2) % MOD);
    }
};
