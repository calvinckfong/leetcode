// 2560. House Robber IV
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int minVal = 1, maxVal = *max_element(nums.begin(), nums.end());

        while (minVal < maxVal)
        {
            int mid = minVal + (maxVal-minVal)/2;
            int cnt = 0;

            for (int i=0; i<n; i++) {
                if (nums[i] <= mid) {
                    cnt++;
                    i++;
                }
            }

            if (cnt < k)    minVal = mid+1;
            else            maxVal = mid; 
        }
        return minVal;
    }
};
