// 498. Diagonal Traverse
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int r=0, c=0, d=1, idx=0;
        vector<int> res(m*n);

        while (r<m && c<n) {
            res[idx++] = mat[r][c];
            int new_r = r - d;
            int new_c = c + d;

            if (new_r<0 || new_c<0 || new_r>=m || new_c>=n) {
                if (d == 1) {
                    r += (c==n-1);
                    c += (c<n-1);
                } else {
                    c += (r==m-1);
                    r += (r<m-1);
                }
                d *= -1;
            } else {
                r = new_r;
                c = new_c;
            }
        }
        return res;
    }
};
