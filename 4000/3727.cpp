// 3727. Maximum Alternating Sum of Squares
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int& x : nums) {
            x *= x; 
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long res = accumulate(nums.begin()+n/2, nums.end(), 0LL);
        res -= accumulate(nums.begin(), nums.begin()+n/2, 0LL);
        
        return res;
    }
};
