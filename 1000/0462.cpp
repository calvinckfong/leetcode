// 462. Minimum Moves to Equal Array Elements II
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto mid = nums.begin() + nums.size()/2;
        ranges::nth_element(nums, mid);
        int median = *mid, res = 0;
        for (int& x: nums)
            res += abs(x - median);
        return res;
    }
};
