// 1464. Maximum Product of Two Elements in an Array
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());

        return (nums[0]-1)*(nums[1]-1);
    }
};
