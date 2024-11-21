// 2257. Count Unguarded Cells in the Grid
class Solution {
public:
    enum {
            Unguarded = 0,
            Guarded,
            Guard,
            Wall
        };
        
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        
        vector<vector<int>> grid(m, vector<int>(n));
        for (vector<int>& w: walls) {
            grid[w[0]][w[1]] = Wall;
        }

        for (vector<int>& g: guards) {
            grid[g[0]][g[1]] = Guard;
        }
        
        bool lineGuarded;
        // Horizontal
        for (int i=0; i<m; i++) {
            lineGuarded = (grid[i][0]==Guard);
            for (int j=1; j<n; j++) {
                lineGuarded = visible(i, j, lineGuarded, grid);
            }

            lineGuarded = (grid[i][n-1]==Guard);
            for (int j=n-2; j>=0; j--) {
                lineGuarded = visible(i, j, lineGuarded, grid);
            }
        }

        // Vertical
        for (int i=0; i<n; i++) {
            lineGuarded = (grid[0][i]==Guard);
            for (int j=1; j<m; j++) {
                lineGuarded = visible(j, i, lineGuarded, grid);
            }

            lineGuarded = (grid[m-1][i]==Guard);
            for (int j=m-2; j>=0; j--) {
                lineGuarded = visible(j, i, lineGuarded, grid);
            }
        }

        int result = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                result += (grid[i][j]==Unguarded);
            }
        }

        return result;
    }

private:
    bool visible(int y, int x, bool lineGuarded, vector<vector<int>>& grid) {
        if (grid[y][x] == Guard) return true;
        if (grid[y][x] == Wall) return false;
        if (lineGuarded) grid[y][x]=Guarded;
        return lineGuarded;
    }
};
