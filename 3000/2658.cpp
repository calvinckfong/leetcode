// 2658. Maximum Number of Fish in a Grid
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int result = 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]>0)
                    result = max(result, dfs(i, j, grid));
            }
        }
        return result;
    }

private:
    int m, n;
    int dfs(int u, int v, vector<vector<int>>& grid) {
        if (u<0 || u>=m || v<0 || v>=n) return 0;
        if (grid[u][v]==0) return 0;
        
        int result = grid[u][v];
        grid[u][v] = 0;
        result += dfs(u+1, v, grid);
        result += dfs(u-1, v, grid);
        result += dfs(u, v+1, grid);
        result += dfs(u, v-1, grid);
        return result;
    }
};
