// 1979. Find Greatest Common Divisor of Array
class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return gcd(nums.front(), nums.back());
    }
};
