// 3739. Count Subarrays With Majority Element II
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), cnt = n;
        vector<int> prefix(n*2+1, 0);
        prefix[n] = 1;

        long long res = 0, preSum = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] == target) {
                preSum += prefix[cnt];
                cnt++;
                prefix[cnt]++;
            } else {
                cnt--;
                preSum -= prefix[cnt];
                prefix[cnt]++;
            }
            res += preSum;
        }
        return res;
    }
};
