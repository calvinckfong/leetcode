// 3471. Find the Largest Almost Missing Integer
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (n==k) {
            return *max_element(nums.begin(), nums.end());
        }

        int cnt[51] = {0};
        for (int& x: nums) {
            cnt[x]++;
        }
        if (k==1) {
            for (int i=50; i>=0; i--) {
                if (cnt[i]==1) return i;
            }
            return -1;
        }

        int res = -1;
        if (cnt[nums[0]]==1) res = max(res, nums[0]);
        if (cnt[nums[n-1]]==1) res = max(res, nums[n-1]);
        return res;
    }
};
