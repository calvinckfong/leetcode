// 62. Unique Paths
class Solution {
public:
    vector<vector<int>> hist;
    int solve(int m, int n)
    {
        if (m==1 || n==1) return 1;
        if (hist[m-1][n] == 0)
            hist[m-1][n] = solve(m-1, n);
        if (hist[m][n-1] == 0)
            hist[m][n-1] = solve(m, n-1);

        return hist[m-1][n] + hist[m][n-1];
    }

    int uniquePaths(int m, int n) {
        hist = vector<vector<int>>(m+1, vector<int>(n+1));
        return solve(m, n);
        
    }
};
