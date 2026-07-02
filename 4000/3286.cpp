// 3286. Find a Safe Walk Through a Grid
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        const int DIRS[5] = {-1, 0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        deque<pair<int, int>> q;
        q.emplace_front(0, 0);
        dist[0][0] = grid[0][0];

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop_front();
            if (cx==m-1 && cy==n-1) return true;

            for (int i=0; i<4; i++) {
                int nx = cx + DIRS[i];
                int ny = cy + DIRS[i+1];
                if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
                int cost = dist[cx][cy] + grid[nx][ny];
                if (cost>=health) continue;

                if (cost<dist[nx][ny]) {
                    dist[nx][ny] = cost;
                    if (grid[nx][ny])   q.emplace_front(nx, ny);
                    else                q.emplace_back(nx, ny);
                }
            }
        }
        return false;
    }
};
