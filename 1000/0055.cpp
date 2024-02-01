// 55. Jump Game
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_pos=nums[0], n=nums.size();
        if (n==1)   return true;

        for (int i=0; i<n; i++)
        {
            // reach end of array
            if (max_pos>=n-1) return true;
            // reach max_pos, no further jump
            if (nums[i]==0 && i==max_pos) return false;
            // accumulate the max_pos can be reached
            max_pos = max(max_pos, i+nums[i]);
        }
        return false;
    }
};
