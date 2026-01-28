// 3651. Minimum Cost Path with Teleportations
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> points;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                points.push_back({i, j});
            }
        }
        sort(points.begin(), points.end(),
            [&](const auto& p1, const auto& p2)->bool{
                return grid[p1.first][p1.second] < grid[p2.first][p2.second];
            });

        int ps = points.size();
        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        for (int t=0; t<=k; t++) {
            int minCost = INT_MAX;
            for (int i=0, j=0; i<ps; i++) {
                int x = points[i].first;
                int y = points[i].second;
                minCost = min(minCost, costs[x][y]);
                if (i+1<ps) {
                    int nx = points[i+1].first;
                    int ny = points[i+1].second;
                    if (grid[x][y]==grid[nx][ny]) continue;
                }
                for (int r=j; r<=i; r++) {
                    costs[points[r].first][points[r].second] = minCost;
                }
                j = i+1;
            }

            for (int i=m-1; i>=0; i--) {
                for (int j=n-1; j>=0; j--) {
                    if (i==m-1 && j==n-1) {
                        costs[i][j] = 0;
                        continue;
                    }
                    if (i!=m-1) {
                        costs[i][j] =  min(costs[i][j], 
                            costs[i+1][j] + grid[i+1][j]);
                    }
                    if (j!=n-1) {
                        costs[i][j] = min(costs[i][j],
                            costs[i][j+1] + grid[i][j+1]);
                    }
                }
            }
        }
        return costs[0][0];
    }
};
