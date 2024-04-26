// 1289. Minimum Falling Path Sum II
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();

        for (int r=1; r<n; r++) {
            for (int c=0; c<n; c++) {
                int minVal = INT_MAX;
                for (int k=0; k<n; k++) {
                    if (k!=c)
                        minVal = min(minVal, grid[r-1][k]);
                }
                grid[r][c] = minVal+grid[r][c];
            }
        }

        return *min_element(grid[n-1].begin(), grid[n-1].end());
    }
};
