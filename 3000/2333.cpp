// 2333. Minimum Sum of Squared Difference
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int k = k1 + k2, d = 0;
        int maxD = 0;
        long long res = 0;

        for (int i=0; i<n; i++) {
            nums1[i] = abs(nums1[i] - nums2[i]);
            maxD = max(maxD, nums1[i]);
        }

        int l=0, r=maxD;
        while (l<=r) {
            int m = (l+r)/2;
            if (check(nums1, m, k)) {
                r = m - 1;
                d = m;
            } else {
                l = m + 1;
            }
        }

        for (int i=0; i<n; i++) {
            if (nums1[i]>d) {
                k -= (nums1[i]-d);
            }
        }

        sort(nums1.begin(), nums1.end(), greater<int>());
        for (int num: nums1) {
            long long diff = (d>=num)?num:d;
            if (k && diff) {
                diff--;
                k--;
            }
            res += diff * diff;
        }

        return res;
    }

private:
    bool check(vector<int>& nums, int mid, int k) {
        long long sum = 0;
        for (int x: nums) {
            sum += (x>mid)?x-mid : 0;
        }
        return sum <= k;
    }
};
