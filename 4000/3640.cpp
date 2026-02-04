// 3640. Trionic Array II
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long res = LLONG_MIN;

        for (int i=0; i<n; i++) {
            int j=i+1;
            for (; j<n && nums[j-1]<nums[j]; j++);
            int p = j-1;
            if (p == i) continue;

            long long tmp = nums[p] + nums[p-1];
            for (; j<n && nums[j-1]>nums[j]; j++) {
                tmp += nums[j];
            }

            int q = j-1;
            if (q==p || q==n-1 || nums[j]<=nums[q]) {
                i = q;
                continue;
            }

            tmp += nums[q+1];

            long long max_sum = 0, sum = 0;
            for (int k=q+2; k<n && nums[k]>nums[k-1]; k++) {
                sum += nums[k];
                max_sum = max(max_sum, sum);
            }
            tmp += max_sum;

            max_sum = 0;
            sum = 0;
            for (int k=p-2; k>=i; k--) {
                sum += nums[k];
                max_sum = max(max_sum, sum);
            }
            tmp += max_sum;
            res = max(res, tmp);
            i = q-1;
        }
        return res;
    }
};
