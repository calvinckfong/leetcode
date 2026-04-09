// 3655. XOR After Range Multiplication Queries II
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const int T = sqrt(n);
        vector<vector<vector<int>>> groups(T);
        for (auto& q: queries) {
            int l=q[0], r=q[1], k=q[2], v=q[3];
            if (k<T) {
                groups[k].push_back({l,r,v});
            } else {
                for (int i=l; i<=r; i+=k) {
                    nums[i] = 1LL * nums[i] * v % MOD;
                }
            }
        }

        vector<long long> diff(n+T);
        for (int k=1; k<T; k++) {
            if (groups[k].size()>0) {
                fill(diff.begin(), diff.end(), 1);
                for (auto& g: groups[k]) {
                    int l=g[0], r=g[1], v=g[2];
                    diff[l] = diff[l] * v % MOD;
                    int R = ((r - l) / k + 1) * k + l;
                    diff[R] = diff[R] * fastPow(v, MOD-2) % MOD;
                }

                for (int i=k; i<n; i++) {
                    diff[i] = diff[i] * diff[i-k] % MOD;
                }

                for (int i=0; i<n; i++) {
                    nums[i] = 1LL * nums[i] * diff[i] % MOD;
                }
            }
        }

        int res = 0;
        for (int i=0; i<n; i++) {
            res = res ^ nums[i];
        }
        return res;
    }

private:
    const int MOD = 1e9 + 7;
    int fastPow(long long x, long long y) {
        long long res = 1;
        while (y>0) {
            if (y&1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }
};
