// 2044. Count Number of Maximum Bitwise-OR Subsets
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        maxOR = 0;
        n = nums.size();
        for (int& num: nums) {
            maxOR |= num;
        }
        return backtrack(nums, 0, 0);
    }

private:
    int maxOR;
    int n;

    int backtrack(vector<int>& nums, int idx, int currOR) {
        if (idx == n) return (currOR==maxOR);
        if (currOR==maxOR) {
            return 1<<(n-idx);
        }
        int res = backtrack(nums, idx+1, currOR|nums[idx]);
        res += backtrack(nums, idx+1, currOR);
        return res;
    }
};
