// 2302. Count Subarrays With Score Less Than K
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long result = 0, sum = 0;
        for (int l=0, r=0; r<n; r++) {
            sum += nums[r];
            while (l<=r && sum * (r-l+1) >= k) {
                sum -= nums[l];
                l++;
            }
            result += (r-l+1);
        }
        return result;
    }
};
