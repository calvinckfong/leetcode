// 840. Magic Squares In Grid
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int result = 0;
        for (int i=0; i<m-2; i++) {
            for (int j=0; j<n-2; j++) {
                result += isMagic(grid, i, j);
            }
        }
        return result;
    }

private:
    bool isMagic(vector<vector<int>>& grid, int i, int j) {
        // test diagonals
        if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != 15) return false;
        if (grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2] != 15) return false;
        // test rows
        if (grid[i][j] + grid[i][j+1] + grid[i][j+2] != 15) return false;
        if (grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] != 15) return false;
        if (grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] != 15) return false;
        // test cols
        if (grid[i][j] + grid[i+1][j] + grid[i+2][j] != 15) return false;
        if (grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] != 15) return false;
        if (grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] != 15) return false;
        // contains all 1 to 9
        int k, cnt[10] = {0};
        for (int y=i; y<i+3; y++) {
            for (int x=j; x<j+3; x++) {
                k = grid[y][x];
                if (k>9) return false;
                cnt[k]++;
                if (cnt[k] > 1) return false;
            }
        }
        return true;
    }
};
