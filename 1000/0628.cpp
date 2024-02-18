// 628. Maximum Product of Three Numbers
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        int p1 = nums[0]*nums[1]*max(nums[2], nums[n-1]);
        int p2 = nums[n-1]*nums[n-2]*nums[n-3];
        return max (p1, p2);
    }
};
