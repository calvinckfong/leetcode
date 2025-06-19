// 2294. Partition Array Such That Maximum Difference Is K
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size(), minV = nums[0];
        for (int i=1; i<n; i++) {
            int currV = nums[i];
            if (currV-minV > k) {
                res++;
                minV = currV;
            }
        }
        return res+1;
    }
};
