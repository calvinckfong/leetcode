// 3191. Minimum Operations to Make Binary Array Elements Equal to One I
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i=0; i<n-2; i++) {
            if (nums[i] == 0) {
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = 1 - nums[i+2];
                result++;
            } 
        }

        return (nums[n-1] && nums[n-2]) ? result : -1;
    }
};
