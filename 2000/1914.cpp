// 1914. Cyclically Rotating a Grid
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int nlayer = min(m/2, n/2);

        for (int l=0; l<nlayer; l++) {
            vector<int> r, c, v;

            for (int i=l; i<m-l-1; i++) {
                r.push_back(i);
                c.push_back(l);
                v.push_back(grid[i][l]);
            }

            for (int i=l; i<n-l-1; i++) {
                r.push_back(m-l-1);
                c.push_back(i);
                v.push_back(grid[m-l-1][i]);
            }

            for (int i=m-l-1; i>l; i--) {
                r.push_back(i);
                c.push_back(n-l-1);
                v.push_back(grid[i][n-l-1]);
            }

            for (int i=n-l-1; i>l; i--) {
                r.push_back(l);
                c.push_back(i);
                v.push_back(grid[l][i]);
            }

            int total = v.size();
            int kk = k % total;
            for (int i=0; i<total; i++) {
                int idx = (i+total-kk) % total;
                grid[r[i]][c[i]] = v[idx];
            }
        }
        return grid;
    }
};
