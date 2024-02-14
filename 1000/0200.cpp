// 200. Number of Islands
class Solution {
public:
    int m, n;
    void growIsland(vector<vector<char>>& grid, int i, int j)
    {
        grid[i][j] = '0';
        if (i>0 && grid[i-1][j]=='1')
            growIsland(grid, i-1, j);
        if (j>0 && grid[i][j-1]=='1')
            growIsland(grid, i, j-1);
        if (i<m-1 && grid[i+1][j]=='1')
            growIsland(grid, i+1, j);
        if (j<n-1 && grid[i][j+1]=='1')
            growIsland(grid, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;

        // Recursive solution
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]=='1')
                {
                    cnt++;
                    growIsland(grid, i, j);
                }
            }
        }
        return cnt;
    }
};
