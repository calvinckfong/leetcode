// 873. Length of Longest Fibonacci Subsequence
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), result=0;
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i=2; i<n; i++) {
            int start=0, end=i-1, sum;

            while (start<end) {
                sum = arr[start] + arr[end];
                if (sum>arr[i])
                    end--;
                else if (sum<arr[i])
                    start++;
                else {
                    dp[end][i] = dp[start][end]+1;
                    result = max(result, dp[end][i]);
                    end--;
                    start++;
                }
            }
        }
        return result==0?0:result+2;
    }
};
