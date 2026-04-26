// 1559. Detect Cycles in 2D Grid
class Solution {
    
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (!visit[i*n+j] && dfs(grid, i, j, -1, -1))
                    return true;
        return false;
    }

private:
    int m, n;
    bitset<501*501> visit;

    bool dfs(vector<vector<char>>& grid, int r, int c, int pr, int pc) {
        static constexpr int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        visit[r*n+c] = 1;
            
        for (const auto& d : dirs) { 
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr != pr || nc != pc)
                if (nr >= 0 && nr < m && nc >= 0 && nc < n)
                    if (grid[nr][nc] == grid[r][c])
                        if (visit[nr*n+nc] || dfs(grid, nr, nc, r, c))
                            return true;
        }
        return false;
    }
};
