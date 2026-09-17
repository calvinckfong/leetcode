// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int res = n+1;
        int s = 0;
        vector<int> dp(n+1, n);

        for (int l=0, r=0; r<n; r++) {
            s += arr[r];
            while (s>target) {
                s -= arr[l++];
            }
            dp[r+1] = dp[r];
            if (s==target) {
                res = min(res, r-l+1+dp[l]);
                dp[r+1] = min(dp[r], r-l+1);
            }
        }

        return (res==n+1)?-1:res;
    }
};
