// 1368. Minimum Cost to Make at Least One Valid Path in a Grid
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        const int m=grid.size(), n=grid[0].size();
        
        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> q;
        q.push_front({0,0});
        minCost[0][0] = 0;

        while (!q.empty()) {
            auto [r,c] = q.front();
            q.pop_front();

            for (int i=0; i<4; i++) {
                int nextR = r + dirs[i][0];
                int nextC = c + dirs[i][1];
                int cost = (grid[r][c]!=i+1);

                if (nextR>=0 && nextR<m && nextC>=0 && nextC<n) {
                    if (minCost[r][c] + cost < minCost[nextR][nextC]) {
                        minCost[nextR][nextC] = minCost[r][c] + cost;
                        if (cost)
                            q.push_back({nextR, nextC});
                        else
                            q.push_front({nextR, nextC});
                    }
                }
            }
        }
        return minCost[m-1][n-1];
    }
};
