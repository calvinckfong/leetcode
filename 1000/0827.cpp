// 827. Making A Large Island
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        unordered_map<int, int> sizes;
        int curr = 2;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    sizes[curr] = dfs(grid, curr, i, j);
                    curr++;
                }
            }
        }

        if (sizes.empty()) return 1;
        if (sizes.size()==1) {
            return sizes[curr-1] + (sizes[curr-1] != m*n);
        }

        int result = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==0) {
                    int currSize = 1;
                    unordered_set<int> neighbours;
                    if (i<m-1 && grid[i+1][j]>1)
                        neighbours.insert(grid[i+1][j]);
                    if (i>0 && grid[i-1][j]>1)
                        neighbours.insert(grid[i-1][j]);
                    if (j<n-1 && grid[i][j+1]>1)
                        neighbours.insert(grid[i][j+1]);
                    if (j>0 && grid[i][j-1]>1)
                        neighbours.insert(grid[i][j-1]);

                    for (auto nb: neighbours)
                        currSize += sizes[nb];
                    
                    if (currSize>result) result = currSize;
                }
            }
        }
        return result;
    }

private:
    int m, n;

    int dfs(vector<vector<int>>& grid, int currID, int i, int j) {
        if (i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1) return 0;

        grid[i][j]= currID;
        return 1 + dfs(grid, currID, i+1, j) + dfs(grid, currID, i-1, j)
            + dfs(grid, currID, i, j+1) + dfs(grid, currID, i, j-1);
    }
};
