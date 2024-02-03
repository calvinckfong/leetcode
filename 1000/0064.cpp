// 64. Minimum Path Sum
class Solution {
public:
    vector<vector<int>> hist;
    void Solve(vector<vector<int>>& grid, int m, int n)
    {
        for (int i=1; i<m+n-1; i++)
        {
            for (int x=0; x<=i; x++)
            {
                int y=i-x;

                if (x<n && y<m)
                {
                    if (y==0)
                        hist[y][x] = grid[y][x] + hist[y][x-1];
                    else if (x==0)
                        hist[y][x] = grid[y][x] + hist[y-1][x];
                    else
                        hist[y][x] = grid[y][x] + min(hist[y-1][x], hist[y][x-1]);
                }
            }
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        hist = vector<vector<int>>(m, vector<int>(n));
        hist[0][0] = grid[0][0];
        Solve(grid, m, n);

        return hist[m-1][n-1];
    }
};
