// 3354. Make Array Elements Equal to Zero
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int l = 0, r = sum;

        for (int i=0; i<n; i++) {
            if (nums[i]==0) {
                int diff = l - r;
                res += (diff>=0 && diff<=1);
                res += (diff<=0 && diff>=-1);
            } else {
                l += nums[i];
                r -= nums[i];
            }
        }
        return res;
    }
};
