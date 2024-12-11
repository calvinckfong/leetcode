// 2779. Maximum Beauty of an Array After Applying Operation
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l=0, r=0, result=0, n=nums.size();

        while (l<n) {
            while (r<n && nums[r] - nums[l] <= 2*k)
                ++r;
            result = max(result, r-l);
            ++l;
        }
        return result;
    }
};
