// 2528. Maximize the Minimum Powered City
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        cnt.resize(n+1);
        for (int i=0; i<n; i++) {
            int ll = max(0, i-r);
            int rr = min(n, i+r+1);
            cnt[ll] += stations[i];
            cnt[rr] -= stations[i];
        }

        long long lo = ranges::min(stations);
        long long hi = accumulate(stations.begin(), stations.end(), (long long)k);
        long long res = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo)/2LL;
            if (check(mid, r, k, n)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }

private:
    vector<long long> cnt;
    bool check(long long val, int r, int k, int n) {
        vector<long long> diff = cnt;
        long long sum = 0;
        long long remain = k;

        for (int i=0; i<n; i++) {
            sum += diff[i];
            if (sum<val) {
                long long add = val - sum;
                if (remain < add) return false;
                remain -= add;
                int end = min(n, i + 2*r + 1);
                diff[end] -= add;
                sum += add;
            }
        }
        return true;
    }
};
