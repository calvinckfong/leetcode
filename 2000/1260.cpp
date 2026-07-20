// 1260. Shift 2D Grid
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int idx = i*n+j;
                int nidx = (idx + k + m*n) % (m*n);
                res[nidx/n][nidx%n] = grid[i][j];
            }
        }

        return res;
    }
};
