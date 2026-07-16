// 3867. Sum of GCD of Formed Pairs
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        int mx = INT_MIN;

        for (int i=0; i<n; i++) {
            mx = max(mx, nums[i]);
            int cm = gcd(nums[i], mx);
            pref[i] = cm;
        }

        sort(pref.begin(), pref.end());

        long long res = 0;
        int l=0, r=n-1;
        while (l<r) {
            res += gcd(pref[l], pref[r]);
            l++;
            r--;
        }
        return res;
    }
};
