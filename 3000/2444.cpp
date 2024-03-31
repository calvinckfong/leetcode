// 2444. Count Subarrays With Fixed Bounds
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        int n=nums.size(), minl=-1, maxl=-1, start=0;

        for (int i=0; i<n; i++) {
            int curr = nums[i];
            if (curr<minK || curr>maxK) {
                minl = maxl = -1;
                start = i+1;
                continue;
            }
            if (curr == minK)   minl = i;
            if (curr == maxK)   maxl = i;
            result += max(0, min(minl, maxl)-start+1);
        }

        return result;
    }
};
