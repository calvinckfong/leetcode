// 3700. Number of ZigZag Arrays II
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n==1) return m;

        int size = m * 2;
        Mat u(size, vector<long long>(size, 0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<i; j++) {
                u[i][j+m] = 1;
            }
            for (int j=i+1; j<m; j++) {
                u[i+m][j] = 1;
            }
        }

        Mat dp(1, vector<long long>(size, 1));
        dp = powMul(std::move(u), n-1, std::move(dp));

        long long res = 0;
        for (int i=0; i<size; i++) {
            res = (res + dp[0][i]) % MOD;
        }
        return res;
    }

private:
    const long long MOD = 1e9 + 7;
    using Mat = vector<vector<long long>>;

    Mat mul(const Mat& a, const Mat& b) {
        int n = a.size();
        int m = b[0].size();
        Mat res(n, vector<long long>(m, 0));

        for (int i=0; i<n; i++) {
            for (int j=0; j<a[0].size(); j++) {
                long long r = a[i][j];
                if (r==0) continue;
                for (int k=0; k<m; k++) {
                    res[i][k] = (res[i][k] + r*b[j][k]) % MOD;
                }
            }
        }
        return res;
    }

    Mat powMul(Mat base, long long exp, Mat res) {
        while (exp>0) {
            if (exp&1) {
                res = mul(res, base);
            }
            base = mul(base, base);
            exp>>=1;
        }
        return res;
    }
};
