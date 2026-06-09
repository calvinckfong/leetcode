// 3689. Maximum Total Subarray Value I
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mx = INT_MIN, mn = INT_MAX;
        for (int n: nums) {
            mx = max(mx, n);
            mn = min(mn, n);
        }

        return (long long)(mx-mn) * k;
    }
};
