// 1498. Number of Subsequences That Satisfy the Given Sum Condition
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> pows(n, 1);
        for (int i=1; i<n; i++) {
            pows[i] = pows[i-1]*2 % MOD;
        }

        int l=0, r=n-1, res=0;
        while (l<=r) {
            if (nums[l] + nums[r] > target)
                r--;
            else {
                res = (res + pows[r-l]) % MOD;
                l++;
            }
        }
        return res;
    }
};
