// 238. Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nNum = nums.size();
        vector<int> ret(nNum, 1);

        for (int i=1; i<nNum; i++)
        {
            ret[i] = ret[i-1] * nums[i-1];
        }

        int right = nums[nNum-1];
        for (int i=nNum-2; i>=0; i--)
        {
            ret[i] *= right;
            right *= nums[i];
        }

        return ret;
    }
};
