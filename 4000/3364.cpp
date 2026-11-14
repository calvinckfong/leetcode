// 3364. Minimum Positive Sum Subarray 
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int res = INT_MAX;

        for (int len=l; len<=r; len++) {
            int sum = 0;
            for (int i=0; i<n; i++) {
                sum += nums[i];
                if (i>=len) sum -= nums[i-len];
                if (i>=len-1 && sum>0 && sum<res) res = sum;
            }
        }

        return (res==INT_MAX)?-1:res;
    }
};
