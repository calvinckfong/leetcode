// 3392. Count Subarrays of Length Three With a Condition
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i=0; i<n-2; i++) {
            result += ((nums[i] + nums[i+2])*2 == nums[i+1]);
        }
        return result;
    }
};
