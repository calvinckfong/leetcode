// 2874. Maximum Value of an Ordered Triplet II
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        long long imax = max(nums[0], nums[1]);
        long long dmax = max(0LL, imax-nums[1]);
        for (int k=2; k<n; k++) {
            result = max(result, dmax * nums[k]);
            imax = max(imax, (long long)nums[k]);
            dmax = max(dmax, imax - (long long)nums[k]);
        }
        return result;
    }
};
