// 3212. Count Submatrices With Equal Frequency of X and Y
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), res=0;
        vector<vector<int>> sum0(n+1, vector<int>(m+1, 0));
        vector<vector<int>> sum1(n+1, vector<int>(m+1, 0));

        for (int i=0; i<n; i++) {
            int i1 = i+1;
            for (int j=0; j<m; j++) {
                int j1=j+1;
                if (grid[i][j] == 'X') {
                    sum0[i1][j1] = sum0[i1][j] + sum0[i][j1] - sum0[i][j] + 1;
                    sum1[i1][j1] = 1;
                } else if (grid[i][j] == 'Y') {
                    sum0[i1][j1] = sum0[i1][j] + sum0[i][j1] - sum0[i][j] - 1;
                    sum1[i1][j1] = sum1[i1][j] | sum1[i][j1];
                } else {
                    sum0[i1][j1] = sum0[i1][j] + sum0[i][j1] - sum0[i][j];
                    sum1[i1][j1] = sum1[i1][j] | sum1[i][j1];
                }
                res += !!(!sum0[i1][j1] && sum1[i1][j1]);
            }
        }

        return res;
    }
};
