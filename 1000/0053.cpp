// 53. Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long sum=INT_MIN, maxSum=INT_MIN;
        for (int i=0; i<nums.size(); i++)
        {
            sum = (sum+nums[i]>nums[i])?sum+nums[i]:nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
