// 1984. Minimum Difference Between Highest and Lowest of K Scores
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k==1) return 0;
        sort(nums.begin(), nums.end(), std::greater<int>());
        int n = nums.size();
        int res = 1e5;
        for (int i=0; i<n-k+1; i++) {
            res = min(res, nums[i]-nums[i+k-1]);
        }
        return res;
    }
};
