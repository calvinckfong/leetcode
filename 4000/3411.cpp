// 3411. Maximum Subarray With Equal Products
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 2;
        int l=0, r=0, prod=1;

        while (r<n) {
            while (gcd(prod, nums[r])>1) {
                prod /= nums[l];
                l++;
            }
            prod *= nums[r];
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
