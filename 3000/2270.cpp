// 2270. Number of Ways to Split Array
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), result = 0;
        long l = 0, r = accumulate(nums.begin(), nums.end(), 0l);

        for (int i=0; i<n-1; i++) {
            l += nums[i];
            r -= nums[i];
            result += (l>=r);
        }
        return result;
    }
};
