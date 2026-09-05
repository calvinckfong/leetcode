// 3904. Smallest Stable Index II
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minV(n);
        minV[n-1] = nums[n-1];
        for (int i=n-2; i>=0; i--) {
            minV[i] = min(minV[i+1], nums[i]);
        }

        int i=0;
        int maxV = INT_MIN;
        for (int& x: nums) {
            if (x>maxV) maxV = x;
            if (maxV-minV[i]<=k) return i;
            i++;
        }
        return -1;
    }
};
