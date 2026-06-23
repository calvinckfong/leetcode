// 3699. Number of ZigZag Arrays I
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;
        vector<int> dp0(m, 0);
        vector<int> dp1(m, 0);
        vector<int> sum0(m+1, 0);
        vector<int> sum1(m+1, 0);

        for (int i=0; i<m; i++) {
            dp0[i] = dp1[i] = 1;
        }

        for (int i=1; i<n; i++) {
            for (int j=0; j<m; j++) {
                sum0[j+1] = (sum0[j] + dp0[j]) % MOD;
                sum1[j+1] = (sum1[j] + dp1[j]) % MOD;
            }

            for (int j=0; j<m; j++) {
                dp0[j] = (sum1[m] - sum1[j+1] + MOD) % MOD;
                dp1[j] = sum0[j];
            }
        }

        auto op = [](int acc, int x) { return (acc+x) % MOD; };
        int res0 = std::reduce(dp0.begin(), dp0.end(), 0, op);
        int res1 = std::reduce(dp1.begin(), dp1.end(), 0, op);

        return (res0+res1) % MOD;
    }
};
