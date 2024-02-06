// 41. First Missing Positive
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n=nums.size();
        int last = 0;
        for (int i=0; i<n; i++)
        {
            if (nums[i]<=0) continue;
            if (nums[i] - last>1) return last+1;
            last = nums[i];
        }

        return max(1, nums[n-1]+1);
    }
};
