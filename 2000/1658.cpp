// 1658. Minimum Operations to Reduce X to Zero
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        if (target<0) return -1;
        if (target==0) return n;

        int longest = -1;
        for (int s=0, l=0, r=0; r<n; r++) {
            s += nums[r];
            while (l<=r && s>target) {
                s -= nums[l++];
            }
            if (s==target) {
                longest = max(longest, r-l+1);
            }
        }
        return (longest==-1) ? -1 : n-longest;
    }
};
