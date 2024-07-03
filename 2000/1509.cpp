// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if (n<5) return 0;

        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        for (int i=0, j=n-4; i<4; i++, j++)
            minDiff = min(minDiff, nums[j]-nums[i]);

        return minDiff;
    }
};
