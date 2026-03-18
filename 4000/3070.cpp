// 3070. Count Submatrices with Top-Left Element and Sum Less Than k
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> sum(m);

        int res = 0;
        for (int i=0; i<n; i++) {
            int r = 0;
            for (int j=0; j<m; j++) {
                sum[j] += grid[i][j];
                r += sum[j];
                if (r<=k) res++;
            }
        }
        return res;
    }
};
