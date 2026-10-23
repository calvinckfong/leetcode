// 3644. Maximum K to Sort a Permutation
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int res = -1;
        for (int i=0; i<n; i++) {
            if (nums[i] != i) res &= nums[i];
        }
        return max(res, 0);
    }
};
