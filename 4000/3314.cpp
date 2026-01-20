// 3314. Construct the Minimum Bitwise Array I
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (auto& x: nums) {
            int res = -1;
            int d = 1;
            while ((x&d) != 0) {
                res = x - d;
                d <<= 1;
            }
            x = res;
        }
        return nums;
    }
};
