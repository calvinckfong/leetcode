// 3381. Maximum Subarray Sum With Length Divisible by K
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long res=LLONG_MIN, sum=0;
        vector<long long> kSum(k, LLONG_MAX/2);
        kSum[k-1] = 0;

        for (int i=0; i<n; i++) {
            sum += nums[i];
            res = max(res, sum-kSum[i%k]);
            kSum[i%k] = min(kSum[i%k], sum);
        }
        return res;
    }
};
