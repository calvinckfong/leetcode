// 1508. Range Sum of Sorted Subarray Sums
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1000000007;
        vector<long long> sums(n*(n+1)/2);
        for (int i=0, k=0; i<n; i++) {
            sums[k++] = nums[i]; 
            for (int j=i+1; j<n; j++) {
                sums[k] = sums[k-1] + nums[j];
                k++;
            }
        }
        sort(sums.begin(), sums.end());
        long long result = 0;
        for (int i=left-1; i<right; i++)
            result = (result + sums[i])%MOD;
        return result;
    }
};
