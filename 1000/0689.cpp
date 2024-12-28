// 689. Maximum Sum of 3 Non-Overlapping Subarrays
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = 0, currMax;

        vector<int> accum(n+1);
        for (int i=0; i<n; i++)
            accum[i+1] = accum[i] + nums[i];

        vector<int> result(3);
        vector<int> left(n);
        for (int i=k, currMax=accum[k]; i<n; i++) {
            if (accum[i+1]-accum[i+1-k] > currMax) {
                left[i] = i+1-k;
                currMax = accum[i+1] - accum[i+1-k];
            } else {
                left[i] = left[i-1];
            }
        }

        vector<int> right(n);
        right[n-k] = n-k;
        for (int i=n-k-1, currMax=accum[n]-accum[n-k]; i>=0; i--) {
            if (accum[i+k]-accum[i] >= currMax) {
                right[i] = i;
                currMax = accum[i+k] - accum[i];
            } else {
                right[i] = right[i+1];
            }
        }

        int total;
        for (int i=k; i<=n-2*k; i++) {
            int lidx = left[i-1];
            int ridx = right[i+k];
            total = (accum[i+k] - accum[i]) + 
                    (accum[lidx+k] - accum[lidx]) +
                    (accum[ridx+k] - accum[ridx]);
            if (total > maxSum) {
                maxSum = total;
                result[0] = lidx;
                result[1] = i;
                result[2] = ridx;
            }
        }
        return result;
    }
};
