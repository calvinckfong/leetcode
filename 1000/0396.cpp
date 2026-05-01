// 396. Rotate Function
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int t = accumulate(nums.begin(), nums.end(), 0);
        int f = 0;
        for (int i=1; i<n; i++) {
            f += i * nums[i];
        }

        int res = f;
        for (int i=n-1; i>0; i--) {
            f += t - n*nums[i];
            res = max(res, f);
        }
        return res;
    }
};
