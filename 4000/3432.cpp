// 3432. Count Partitions with Even Sum Difference
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0);
        for (int i=0; i<n-1; i++) {
            l += nums[i];
            r -= nums[i];
            res += ((l-r)%2 == 0);
        }
        return res;
    }
};
