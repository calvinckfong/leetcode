// 3619. Count Islands With Total Value Divisible by K
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        int res = 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]>0 && (dfs(i, j, grid)%k==0)) {
                    res++;
                }
            }
        }
        return res;
    }

private:
    int m, n;
    long dfs(int i, int j, vector<vector<int>>& grid) {
        const int DIRS[5] = {-1, 0, 1, 0, -1};
        long res = grid[i][j];
        grid[i][j] = 0;
        for (int d=0; d<4; d++) {
            int x = i + DIRS[d];
            int y = j + DIRS[d+1];
            if (x>=0 && x<m && y>=0 && y<n && grid[x][y]>0) {
                res += dfs(x, y, grid);
            }
        }
        return res;
    }
};
