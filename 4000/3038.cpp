// 3038. Maximum Number of Operations With the Same Score I
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int i, sum = nums[0]+nums[1];
        for (i=2; i<nums.size()-1; i+=2)
        {
            if (nums[i] + nums[i+1] != sum) break;
        }
        return i/2;
    }
};
