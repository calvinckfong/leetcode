// 2460. Apply Operations to an Array
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size(), nz=0;
        vector<int> result;
        for (int i=0; i<n-1; i++) {
            if (nums[i]) {
                if (nums[i] == nums[i+1]) {
                    nums[i] *= 2;
                    nums[i+1] = 0;
                }
                result.push_back(nums[i]);
            }
        }
        if (nums[n-1]) result.push_back(nums[n-1]);
        while (result.size()<n)
            result.push_back(0);
        
        return result;
    }
};
