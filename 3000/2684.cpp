// 2684. Maximum Number of Moves in a Grid
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int result =0;
        for (int i=0; i<m; i++) {
            int move = dfs(i, 0, grid, dp);
            result = max(result, move);
        }

        return result;
    }

private:
    int m, n;
    int dfs(int y, int x, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (dp[y][x]>=0) return dp[y][x];

        int maxVal = 0;
        int num = grid[y][x];
        for (int i=-1; i<=1; i++) {
            int yy = y+i;
            if (yy>=0 && yy<m && x+1<n)
                if (grid[yy][x+1]>num)
                    maxVal = max(maxVal, 1+dfs(yy, x+1, grid, dp));
        } 
        dp[y][x] = maxVal;
        return maxVal;
    }
};
