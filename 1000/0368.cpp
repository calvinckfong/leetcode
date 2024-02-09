// 368. Largest Divisible Subset
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), maxlen=1;
        vector<int> dp(n, 1);   // each element is at least self-divisible

        for (int i=1; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if ((nums[i]%nums[j]==0) && dp[i]<dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    maxlen = max(maxlen, dp[i]);
                }
            }
        }

        int prev=-1;
        vector<int> result;
        for (int i=n-1; i>=0; i--)
        {
            if (dp[i]==maxlen && (prev==-1 || (prev%nums[i]==0)))
            {
                prev = nums[i];
                result.push_back(prev);
                maxlen--;
            }
        }

        return result;
    }
};
