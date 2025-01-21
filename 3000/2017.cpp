// 2017. Grid Game
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long rowSum0 = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long rowSum1 = 0, minSum = LONG_LONG_MAX;
        int n = grid[0].size();

        for (int i=0; i<n; i++) {
            rowSum0 -= grid[0][i];
            minSum = min(minSum, max(rowSum0, rowSum1));
            rowSum1 += grid[1][i];
        }
        return minSum;
    }
};
