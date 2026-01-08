// 1458. Max Dot Product of Two Subsequences
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1; n2 = nums2;
        n = nums1.size();
        m = nums2.size();
        dp.assign(n, vector<int>(m, MIN_VALUE));

        return solve(0, 0);
    }

private:
    const int MIN_VALUE = INT_MIN/2;
    int m, n;
    vector<int> n1, n2;
    vector<vector<int>> dp;

    int solve(int i, int j) {
        if (i==n || j==m) return MIN_VALUE;
        if (dp[i][j]!=MIN_VALUE)  return dp[i][j];

        int prod = n1[i] * n2[j];
        int res = max({prod, 
                prod + solve(i+1, j+1), 
                solve(i+1, j),
                solve(i, j+1)});
        dp[i][j] = res;
        return res;
    }
};
