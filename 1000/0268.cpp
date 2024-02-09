// 268. Missing Number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0);
        long long expected_total = (0+n)*(n+1)/2;
        return expected_total-total;
    }
};
