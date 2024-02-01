// 45. Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(), max_pos = nums[0];
        if (n==1) return 0;

        int cnt = 1;
        for (int i=0; i<n; i++)
        {
            if (max_pos>=n-1) return cnt;   
            if (max_pos+nums[i]>=n-1) return cnt+1;
            if (nums[i]+i>max_pos)
            {
                max_pos = nums[i]+i;
                cnt++;
            }
                     
        }
        return cnt+1;
    }
};
