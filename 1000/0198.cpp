// 198. House Robber
class Solution {
public:
    int rob(vector<int>& nums) {
        int sum1=0, sum2=0;
        int next_sum1, next_sum2;
        for (int i=0; i<nums.size(); i++)
        {
            // skip current horse, so find the best path
            next_sum2 = max(sum1, sum2);
            // rob current horse, only sum2 in previous stage can rob
            sum1 = sum2 + nums[i];
            // update
            sum2 = next_sum2;
        }
        return max(sum1, sum2);
    }
};
