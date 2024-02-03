// 1043. Partition Array for Maximum Sum
class Solution {
public:
    int maxSum(int pos, vector<int>& arr, int k, vector<int>& dp)
    {
        if (pos > arr.size()-1) return 0;
        if (dp[pos]!=-1)   return dp[pos];

        int l = 0;
        int maxVal = INT_MIN;
        int maxS = INT_MIN;
        int ret=0;

        for (int i=pos; i<pos+k && i<arr.size(); i++)
        {
            l++; 
            maxVal = max(maxVal, arr[i]);
            maxS = maxVal*l + maxSum(i+1, arr, k, dp);
            ret = max(ret, maxS);
        }

        dp[pos] = ret;
        return ret;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return maxSum(0, arr, k, dp);
    }
};
