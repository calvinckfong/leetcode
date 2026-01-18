// 1895. Largest Magic Square
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        vector<vector<int>> rsum(m, vector<int>(n));
        vector<vector<int>> csum(m, vector<int>(n));
        for (int i=0; i<m; i++) {
            rsum[i][0] = grid[i][0];
            for (int j=1; j<n; j++) {
                rsum[i][j] = rsum[i][j-1] + grid[i][j];
            }
        }
        for (int j=0; j<n; j++) {
            csum[0][j] = grid[0][j];
            for (int i=1; i<m; i++) {
                csum[i][j] = csum[i-1][j] + grid[i][j];
            }
        }

        for (int e = min(m,n); e>=2; e--) {
            for (int i=0; i<=m-e; i++) {
                for (int j=0; j<=n-e; j++) {
                    int sum = rsum[i][j+e-1] - (j?rsum[i][j-1]:0);
                    bool valid = true;
                    for (int ii=i+1; ii<i+e; ii++) {
                        if (rsum[ii][j+e-1] - (j?rsum[ii][j-1]:0) != sum) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    for (int jj=j; jj<j+e; jj++) {
                        if (csum[i+e-1][jj] - (i?csum[i-1][jj]:0) != sum) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    int d1=0, d2=0;
                    for (int k=0; k<e; k++) {
                        d1 += grid[i+k][j+k];
                        d2 += grid[i+k][j+e-k-1];
                    }
                    if (d1==sum && d2==sum) return e;
                }
            }
        }
        return 1;
    }
};
