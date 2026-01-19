// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> P(m+1, vector<int>(n+1));
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                P[i][j] = P[i-1][j] + P[i][j-1] - P[i-1][j-1] + mat[i-1][j-1];
            }
        }

        int r = min(m, n);
        int res = 0;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                for (int k=res+1; k<=r; k++) {
                    if (i+k-1<=m && j+k-1<=n) {
                        if (getRect(P, i-1, j-1, k) <= threshold)
                            res++;
                    } else {
                        break;
                    }
                }
            }
        }
        return res;
    }

private:
    int getRect(const vector<vector<int>>& P, int x, int y, int d) {
        return P[x+d][y+d] - P[x][y+d] - P[x+d][y] + P[x][y];
    }
};
