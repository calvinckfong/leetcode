// 1621. Number of Sets of K Non-Overlapping Line Segments
class Solution {
public:
    int numberOfSets(int n, int k) {
        int m = 2*k;
        long long num=1, den=1;
        for (int i=1; i<=m; i++) {
            num = num * (n+k-i) % MOD;
            den = den * i % MOD;
        }
        return num * quickPow(den, MOD-2) % MOD;
    }

private:
    const int MOD = 1e9 + 7;
    long long quickPow(long long x, long long e) {
        long long res = 1;
        while (e>0) {
            if (e&1) res = res * x % MOD;
            x = x * x % MOD;
            e >>= 1;
        }
        return res;
    }
};
