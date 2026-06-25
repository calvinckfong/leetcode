// 3737. Count Subarrays With Majority Element I
class FenwickTree {
public:
    FenwickTree(int _n) : n(_n) {
        bit.assign(n+1, 0);
    }

    void update(int idx, int val) {
        while (idx<=n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx>0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

private:
    vector<int> bit;
    int n;
};

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);

        for (int i=0; i<n; i++) {
            prefix[i+1] = prefix[i] + (nums[i] == target?1:-1);
        }

        vector<int> val = prefix;
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());

        FenwickTree bit(val.size());
        long long res = 0;

        for (int x: prefix) {
            int idx = lower_bound(val.begin(), val.end(), x) - val.begin() + 1;
            res += bit.query(idx-1);
            bit.update(idx, 1);
        }

        return static_cast<int>(res);
    }
};
