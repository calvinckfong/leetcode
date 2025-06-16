// 2016. Maximum Difference Between Increasing 
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int minV = nums[0], res=-1;
        
        for (int i=1; i<n; i++) {
            if (nums[i]<=minV)
                minV = nums[i];
            else
                res = max(res, nums[i]-minV);
        }
        return res;
    }
};
