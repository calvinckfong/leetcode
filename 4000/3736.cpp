// 3736. Minimum Moves to Equal Array Elements III
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxV = *max_element(nums.begin(), nums.end());
        int res = 0;
        for (auto& x: nums) {
            res += maxV-x;
        }
        return res;
    }
};
