// 861. Score After Flipping Matrix
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();

        for (int i=0; i<m; i++) {
            if (grid[i][0] == 0) {
                for (int j=0; j<n; j++)
                    grid[i][j] = 1-grid[i][j];
            }
        }
        
        for (int i=0; i<n; i++) {
            int cntOne = 0;
            for (int j=0; j<m; j++) {
                cntOne += grid[j][i];
            }
            if (cntOne*2<m) {
                for (int j=0; j<m; j++) {
                    grid[j][i] = 1-grid[j][i];
                }
            }
        }

        int result=0;
        for (int i=0; i<m; i++) {
            int num=0;
            for (int j=0; j<n; j++)
                num = num*2 + grid[i][j];
            result += num;
        }
        return result;
    }
};
