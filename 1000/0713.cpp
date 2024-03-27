// 713. Subarray Product Less Than K
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l, r, n=nums.size();
        int prod, result=0;
        for (l=0; l<n; l++)
        {
            r = l;
            prod = 1;
            while (r<n) {
                prod *= nums[r++];
                if (prod>=k) break;
                result++;
            }
        }
        return result;
    }
};
