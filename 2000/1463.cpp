// 1463. Cherry Pickup II
class Solution {
public:
    int m, n;
    /* Slow intuitive solution
    int pick(int row, int col1, int col2, vector<vector<int>>& grid)
    {
        if (row==m) return 0;   // last row
        if (col1<0||col1>=n) return 0;  // col1 boundary
        if (col2<0||col2>=n) return 0;  // col2 boundary
        if (col1==col2) return 0;   // col1 and col2 cannot share the same position

        //int sum = grid[row][col1] + grid[row][col2];
        int next = 0;
        for (int i=col1-1; i<col1+2; i++)
            for (int j=col2-1; j<col2+2; j++) {
                if (i==j) continue;
                next = max(next, pick(row+1, i, j, grid));
            }

        return grid[row][col1] + grid[row][col2] + next;
    }
    */

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int dp[m][n][n];
        for (int k=0; k<m; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    dp[k][j][i] = -1;

        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];
        int prev, maxVal=0;
        for (int k=1; k<m; k++)
        {
            for (int j=0; j<n; j++)
            {
                for (int i=0; i<n; i++)
                {
                    prev = dp[k-1][j][i];
                    if (prev>=0)
                    {
                        for (int r1=max(0, j-1); r1<min(n, j+2); r1++)
                        {
                            for (int r2=max(0, i-1); r2<min(n, i+2); r2++)
                            {
                                if (r1==r2) continue;
                                dp[k][r1][r2] = max(dp[k][r1][r2], prev+grid[k][r1]+grid[k][r2]);
                                if (k==m-1)
                                    maxVal = max(maxVal, dp[k][r1][r2]);
                            }
                        }
                    }
                }
            }
        }
        return maxVal;
    }
};
