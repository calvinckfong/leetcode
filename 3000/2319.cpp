// 2319. Check if Matrix Is X-Matrix
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int i, j, v, n = grid.size();

        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                v = grid[i][j];
                if (i==j || i+j==n-1) {
                    if (!v) return false;
                } else {
                    if (v) return false;
                }
            }
        }

        return true;
    }
};
