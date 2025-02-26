// 1749. Maximum Absolute Sum of Any Subarray
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minSum=0, maxSum=0, sum=0;
        for (int& num: nums) {
            sum += num;
            minSum = min(minSum, sum);
            maxSum = max(maxSum, sum);
        }
        return maxSum - minSum;
    }
};
