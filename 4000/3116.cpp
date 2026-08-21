// 3116. Kth Smallest Amount With Single Denomination Combination
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        vector<int> new_coins;
        for (int& c: coins) {
            bool valid = true;
            for (int nc: new_coins) {
                if (c % nc == 0) {
                    valid = false;
                    break;
                }
            }
            if (valid)  new_coins.push_back(c);
        }
        coins = new_coins;

        int n = coins.size();
        m = (1<<n);
        vector<int> bit_count(m);
        lcm = vector<long long>(m, 1);
        long long l = k, r = 1LL * coins[0] * k + 1;

        for (int mask=1; mask<m; mask++) {
            int pre_mask = mask & (mask-1);
            int i = __builtin_ctz(mask);

            long long tmp = lcm[pre_mask] / gcd(lcm[pre_mask], coins[i]);
            if (tmp <= r/coins[i]) {
                lcm[mask] = tmp * coins[i];
            } else {
                lcm[mask] = r+1;
            }
        }

        while (l<r) {
            long long mid = (l+r)/2;
            if (get(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

private:
    int m;
    vector<long long> lcm;

    long long get(long long x) {
        long long res = 0;
        for (int mask=1; mask<m; mask++) {
            if (lcm[mask] > x) {
                continue;
            }
            if (__builtin_popcount(mask) & 1) {
                res += x / lcm[mask];
            } else {
                res -= x / lcm[mask];
            }
        }
        return res;
    }
};
