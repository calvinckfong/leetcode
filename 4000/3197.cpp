// 3197. Find the Minimum Area to Cover All Ones II
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int res = solve(grid);
        rotate(grid);
        return min(res, solve(grid));
    }

private:
    int m, n;

    int solve(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = m*n;

        for (int i=0; i<m-1; i++) {
            for (int j=0; j<n-1; j++) {
                res = min(res, minSum(grid, 0,   i,   0,   n-1) +
                               minSum(grid, i+1, m-1, 0,   j) +
                               minSum(grid, i+1, m-1, j+1, n-1));
                res = min(res, minSum(grid, 0,   i,   0,   j) +
                               minSum(grid, 0,   i,   j+1, n-1) +
                               minSum(grid, i+1, m-1, 0,   n-1));
            }
        }

        for (int i=0; i<m-2; i++) {
            for (int j=i+1; j<m-1; j++) {
                res = min(res, minSum(grid, 0,   i,   0, n-1) + 
                               minSum(grid, i+1, j,   0, n-1) +
                               minSum(grid, j+1, m-1, 0, n-1));
            }
        }
        return res;
    }

    int minSum(vector<vector<int>>& grid, int u, int d, int l, int r) {
        int min_i = m, min_j = n;
        int max_i = 0, max_j = 0;
        for (int i=u; i<=d; i++) {
            for (int j=l; j<=r; j++) {
                if (grid[i][j]) {
                    min_i = min(min_i, i);
                    max_i = max(max_i, i);
                    min_j = min(min_j, j);
                    max_j = max(max_j, j);
                }
            }
        }
        return (min_i<=max_i) ? (max_i-min_i+1) * (max_j-min_j+1) : m*n;
    }

    void rotate(vector<vector<int>>& grid) {
        vector<vector<int>> rgrid(n, vector<int>(m));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                rgrid[n-j-1][i] = grid[i][j];
            }
        }
        grid = rgrid;
    }
};
