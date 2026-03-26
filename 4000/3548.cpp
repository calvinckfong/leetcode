// 3548. Equal Sum Grid Partition II
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        for (auto& r: grid) {
            total += accumulate(r.begin(), r.end(), 0LL);
        }

        unordered_set<long long> exist;
        for (int k=0; k<4; k++) {
            exist.clear();
            exist.insert(0);
            long long sum = 0, tag;
            int m = grid.size(), n = grid[0].size();
            if (m<2) {
                grid = rotate(grid);
                continue;
            }

            if (n==1) {
                for (int i=0; i<m-1; i++) {
                    sum += grid[i][0];
                    tag = sum*2 - total;
                    if (tag==0 || tag==grid[0][0] || tag==grid[i][0]) 
                        return true;
                }
                grid = rotate(grid);
                continue;
            }

            for (int i=0; i<m-1; i++) {
                for (int j=0; j<n; j++) {
                    exist.insert(grid[i][j]);
                    sum += grid[i][j];
                }
                tag = sum*2 - total;
                if (i==0) {
                    if (tag==0 || tag==grid[0][0] || tag==grid[0][n-1]) 
                        return true;
                    continue;
                }
                if (exist.contains(tag)) return true;
            }
            grid = rotate(grid);
        }
        return false;
    }

private:
    vector<vector<int>> rotate(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector tmp(n, vector<int>(m));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                tmp[j][m-1-i] = grid[i][j];
            }
        }
        return tmp;
    }
};
