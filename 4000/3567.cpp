// 3567. Minimum Absolute Difference in Sliding Submatrix
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m-k+1, vector<int>(n-k+1));

        for (int i=0; i<m-k+1; i++) {
            for (int j=0; j<n-k+1; j++) {
                vector<int> cand;
                cand.reserve(k*k);
                for (int x=i; x<i+k; x++) {
                    for (int y=j; y<j+k; y++) {
                        cand.push_back(grid[x][y]);
                    }
                }

                int kmin = INT_MAX;
                sort(cand.begin(), cand.end());
                for (int k=1; k<cand.size(); k++) {
                    if (cand[k] == cand[k-1]) continue;
                    kmin = min(kmin, cand[k]-cand[k-1]);
                }
                if (kmin != INT_MAX) res[i][j] = kmin;
            }
        }

        return res;
    }
};
