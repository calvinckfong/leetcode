// 3505. Minimum Operations to Make Elements Within K Subarrays Equal
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        n = nums.size();
        vector<long long> ops = getCosts(nums, x);
        vector<long long> prev(n+1, 0);
        vector<long long> curr(n+1, LLONG_MAX);

        for (int i=1; i<=k; i++) {
            fill(curr.begin(), curr.end(), LLONG_MAX);
            for (int j=i*x; j<=n; j++) {
                curr[j] = min(curr[j-1], prev[j-x] + ops[j-1]);
            }
            prev.swap(curr);
        }
        return prev[n];
    }

private:
    int n;

    vector<long long> getCosts(const vector<int>& nums, int x) {
        vector<long long> ops(n);
        multiset<int> l, r;
        long long sumL=0, sumR=0;

        for (int i=0; i<n; i++) {
            int v = nums[i];
            if (l.empty() || v<=*l.rbegin()) {
                l.insert(v);
                sumL += v;
            } else {
                r.insert(v);
                sumR += v;
            }

            if (i>=x) {
                v = nums[i-x];
                auto it = l.find(v);
                if (it != l.end()) {
                    sumL -= v;
                    l.erase(it);
                } else {
                    it = r.find(v);
                    sumR -= v;
                    r.erase(it);
                }
            }

            if (l.size() > r.size() + 1) {
                auto it = prev(l.end());
                v = *it;
                r.insert(v);
                l.erase(it);
                sumL -= v;
                sumR += v;
            } else if (l.size() < r.size()) {
                auto it = r.begin();
                v = *it;
                l.insert(v);
                r.erase(it);
                sumL += v;
                sumR -= v;
            }

            if (i>=x-1) {
                long long m = *l.rbegin();
                long long lCost = m * l.size() - sumL;
                long long rCost = sumR - m * r.size();
                ops[i] = lCost + rCost;
            }
        }
        return ops;
    }
};
