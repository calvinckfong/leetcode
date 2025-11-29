// 3512. Minimum Operations to Make Array Sum Divisible by K
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        for (int& x: nums) {
            res = (res + x) % k;
        }
        return res;
    }
};
