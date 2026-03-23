// 1594. Maximum Non Negative Product in a Matrix
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> maxGT(m, vector<long long>(n));
        vector<vector<long long>> minLT(m, vector<long long>(n));

        maxGT[0][0] = minLT[0][0] = grid[0][0];
        for (int i=1; i<n; i++) {
            maxGT[0][i] = minLT[0][i] = maxGT[0][i-1] * grid[0][i];
        }
        for (int i=1; i<m; i++) {
            maxGT[i][0] = minLT[i][0] = maxGT[i-1][0] * grid[i][0];
        }

        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                long long val = grid[i][j];
                if (grid[i][j] >= 0) {
                    maxGT[i][j] = (val * max(maxGT[i][j-1], maxGT[i-1][j]));
                    minLT[i][j] = (val * min(minLT[i][j-1], minLT[i-1][j]));
                } else {
                    maxGT[i][j] = (val * min(minLT[i][j-1], minLT[i-1][j]));
                    minLT[i][j] = (val * max(maxGT[i][j-1], maxGT[i-1][j]));
                }
            }
        }

        if (maxGT[m-1][n-1]<0) return -1;
        else return (maxGT[m-1][n-1]) % MOD;
    }
};
