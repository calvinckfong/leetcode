// 3539. Find Sum of Array Product of Magical Sequences
class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> fac(m+1, 1);
        for (int i=1; i<=m; i++) {
            fac[i] = fac[i-1] * i%MOD;
        }

        vector<long long> ifac(m+1, 1);
        for (int i=2; i<=m; i++) {
            ifac[i] = quickmul(i, MOD-2);
        }
        for (int i=2; i<=m; i++) {
            ifac[i] = ifac[i-1] * ifac[i] % MOD;
        }

        vector<vector<long long>> numPower(n, vector<long long>(m+1, 1));
        for (int i=0; i<n; i++) {
            for (int j=1; j<=m; j++) {
                numPower[i][j] = numPower[i][j-1] * nums[i] % MOD;
            }
        }

        vector f(n, vector(m+1, vector(m*2+1, vector<long long>(k+1, 0))));
        for (int j=0; j<=m; j++) {
            f[0][j][j][0] = numPower[0][j] * ifac[j] % MOD;
        }
        for (int i=0; i+1<n; i++) {
            for (int j=0; j<=m; j++) {
                for (int p=0; p<=m*2; p++) {
                    for (int q=0;q<=k; q++) {
                        int q2 = p%2 + q;
                        if (q2>k) break;

                        for (int r=0; r+j<=m; r++) {
                            int p2 = p/2 + r;
                            f[i+1][j+r][p2][q2] += f[i][j][p][q] *
                                    numPower[i+1][r] % MOD * ifac[r] % MOD;
                            f[i+1][j+r][p2][q2] %= MOD;
                        }
                    }
                }
            }
        }
        long long res = 0;
        for (int p=0; p<=m*2; p++) {
            for (int q=0; q<=k; q++) {
                if (__builtin_popcount(p)+q == k) {
                    res += f[n-1][m][p][q] * fac[m]%MOD;
                    res %= MOD; 
                }
            }
        }
        return res;
    }

private:
    const long long MOD = 1e9 + 7;
    long long quickmul(long long x, long long y) {
        long long res = 1;
        long long cur = x % MOD;
        while (y) {
            if (y&1) {
                res *= cur;
                res %= MOD;
            }
            y >>= 1;
            cur *= cur;
            cur %= MOD; 
        }
        return res;
    }
};
