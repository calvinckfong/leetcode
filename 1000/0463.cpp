// 463. Island Perimeter
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result=0, m=grid.size(), n=grid[0].size();
        // Inner
        for (int i=0; i<m-1; i++) {
            for (int j=0; j<n; j++) {
                result += abs(grid[i][j] - grid[i+1][j]);
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n-1; j++) {
                result += abs(grid[i][j] - grid[i][j+1]);
            }
        }
        // outer boundary
        for (int i=0; i<m; i++) {
            result += grid[i][0];
            result += grid[i][n-1];
        }
        for (int i=0; i<n; i++) {
            result += grid[0][i];
            result += grid[m-1][i];
        }

        return result;
    }
};
