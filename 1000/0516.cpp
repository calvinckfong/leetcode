// 516. Longest Palindromic Subsequence
class Solution {
public:
    int solve(string& s, int l, int r, vector<vector<int>>& dp)
    {
        if (l==r) return 1; // same char
        if (l>r) return 0; // invalid
        if (dp[l][r]!=-1) return dp[l][r]; // pre-computed

        if (s[l] == s[r]) return 2 + solve(s, l+1, r-1, dp); // shrink both sides
        int rightside = solve(s, l+1, r, dp); // shrink from left
        int leftside = solve(s, l, r-1, dp); // shrink from right
        dp[l][r] = max(rightside, leftside); // chars can be deleted, so take the max value
        return dp[l][r];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n-1, dp);
    }
};
