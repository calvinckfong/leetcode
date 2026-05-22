// 33. Search in Rotated Sorted Array
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, n=nums.size(), r=n-1;
        int m;

        while (l<r) {
            m = (l+r)/2;
            if (nums[m] > nums.back())
                l = m+1;
            else
                r = m;
        }

        int rot = l, idx;
        l=0, r=n-1;
        while (l<=r) {
            m = (l+r)/2;
            idx = (m + rot) % n;
            if (nums[idx] == target) return idx;

            if (nums[idx] < target)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }
};
