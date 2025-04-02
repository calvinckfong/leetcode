// 2873. Maximum Value of an Ordered Triplet I
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        long long imax = max(nums[0], nums[1]);
        long long dmax = max(0LL, imax - nums[1]);
        for (int k=2; k<n; k++) {
            result = max(result, nums[k]*dmax);
            imax = max(imax, (long long)nums[k]);
            dmax = max(dmax, imax-nums[k]);
        }
        return result;
    }
};
