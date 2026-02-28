// 1680. Concatenation of Consecutive Binary Numbers
class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        int nbit=1;
        long res = 0;
        for (int i=1; i<=n; i++) {
            if (i >= (1<<nbit)) nbit++;
            res = ((res << nbit) + i) % MOD;
        }
        return res;
    }
};
