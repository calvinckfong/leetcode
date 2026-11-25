// 3934. Smallest Unique Subarray
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        n = nums.size();
        h = vector<long long>(n+1);
        p = vector<long long>(n+1);
        p[0] = 1;
        for (int i=0; i<n; i++) {
            h[i+1] = (h[i] * BASE + nums[i]) % MOD;
            p[i+1] = p[i] * BASE % MOD;
        }

        int lo = 1, hi = n;
        while (lo<hi) {
            int m = (hi+lo)/2;

            if (check(m))   hi = m;
            else            lo = m + 1;
        }
        return lo;
    }

private:
    const long long MOD = 1000000007LL;
    const long long BASE = 911382323LL;
    int n;
    vector<long long> h, p;
    bool check(int x) {
        unordered_map<long long, int> cnt;
        for (int l=0; l+x<=n; l++) {
            int r = l+x;
            long long key = (h[r] - h[l]*p[x]%MOD + MOD) % MOD;
            cnt[key]++;
        }

        for (auto& [_, count]: cnt) {
            if (count==1) return true;
        }
        return false;
    }
};
