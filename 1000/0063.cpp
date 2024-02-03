// 63. Unique Paths II
class Solution {
public:
    vector<vector<int>> freq;
    void Solve(vector<vector<int>>& obstacleGrid, int m, int n)
    {
        for (int i=1; i<m+n-1; i++)
        {
            for (int x=0; x<=i; x++)
            {
                int y=i-x;

                if (y<m && x<n)
                {
                    if (obstacleGrid[y][x]) continue;

                    if (x==0)
                        freq[y][x] = freq[y-1][x];
                    else if (y==0)
                        freq[y][x] = freq[y][x-1];
                    else
                        freq[y][x] = freq[y-1][x] + freq[y][x-1];
                }
            }
        }
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        freq = vector<vector<int>>(m, vector<int>(n));
        freq[0][0] = 1-obstacleGrid[0][0];
        Solve(obstacleGrid, m, n);
        return freq[m-1][n-1];
    }
};
