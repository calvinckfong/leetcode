// 2044. Count Number of Maximum Bitwise-OR Subsets
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size(), k=0;
        if (n==1) return 1;

        int maxOrSum = 0;
        for (int i=0; i<n; i++)
            maxOrSum |= nums[i];
        while (maxOrSum) {
            maxOrSum>>=1;
            k++;
        }

        vector<int> dp(1<<k, 0);
        dp[0] = 1;
        
        maxOrSum = 0;
        for (int i=0; i<n; i++) {
            for (int j=maxOrSum; j>=0; j--) {
                dp[j|nums[i]] += dp[j];
            }
            maxOrSum |= nums[i];
        }
        return dp[maxOrSum];
    }
};
