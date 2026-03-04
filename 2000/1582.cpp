// 1582. Special Positions in a Binary Matrix
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> col(m, 0);
        vector<int> row(n, 0);

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j]) {
                    col[i]++;
                    row[j]++;
                }
            }
        }

        int res = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] && col[i]==1 && row[j]==1) {
                    res++;
                }
            }
        }
        
        return res;
    }
};
