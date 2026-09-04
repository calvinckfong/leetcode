// 3903. Smallest Stable Index I
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(), i=0, last = -1;
        int maxV = INT_MIN, minV = *min_element(nums.begin(), nums.end());
        for (int& x: nums) {
            if (x > maxV) maxV = x;
            if (last == minV) minV = *min_element(nums.begin()+i, nums.end());
            if (maxV-minV <= k) return i;
            i++;
            last = x;
        }
        return -1;
    }
};
