// 3041. Maximize Consecutive Elements in an Array After Modification
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = 0, max0 = 0, max1 = 0, res = 0;
        for (auto x: nums) {
            if (x == prev+2) {
                max0 = max1+1;
                max1 = 1;
            } else if (x == prev + 1) {
                max0++;
                max1++;
            } else if (x == prev) {
                max1 = max(max1, max0+1);
            } else {
                max0 = max1 = 1;
            }
            res = max({res, max0, max1});
            prev = x;
        }
        return res;
    }
};
