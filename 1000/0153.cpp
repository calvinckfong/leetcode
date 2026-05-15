// 153. Find Minimum in Rotated Sorted Array
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int m;

        while (l<r) {
            m = (l+r)/2;

            if (nums[m] < nums[r]) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return nums[l];
    }
};
