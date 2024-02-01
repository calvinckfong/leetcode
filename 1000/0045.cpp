// 45. Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(), end_pos=0, start_pos=0, cnt=0;
        if (n==1) return 0;

        while (end_pos<n-1)
        {
            // search between [start_pos, end_pos], the max_pos can reach 
            int max_pos = 0, p;
            for (int i=start_pos; i<=end_pos; i++)
            {
                p = i+nums[i];
                max_pos = (max_pos>p)?max_pos:p;
            }

            // update next range
            start_pos = end_pos+1;
            end_pos = max_pos;
            cnt++;
        }
        return cnt;
    }
};
