// 209. Minimum Size Subarray Sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total < target) return 0;
        else if (total == target) return n;

        int minLen = INT_MAX;
        int sum=0, l=0;
        for (int i=0; i<n; i++)
        {
            sum += nums[i];
            while (sum>=target)
            {
                minLen = min(minLen, i+1-l);
                sum -= nums[l++];
            }
        }
        return (minLen==INT_MAX)?0:minLen;
    }
};
