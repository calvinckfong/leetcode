// 2812. Find the Safest Path in a Grid
class Solution {
public:
    const int MAX_DIST = 500*2;
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0]==1 || grid[n-1][n-1]==1) return 0;

        vector<vector<int>> safeness(n, vector<int>(n, MAX_DIST));
        vector<vector<char>> visited(n, vector<char>(n, 0));
        buildSafeness(grid, safeness, n);

        priority_queue<array<int, 3>> q;
        q.push({safeness[0][0], 0, 0});
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int s=it[0], y=it[1], x=it[2];
            result = min(result, s);
            if (y==n-1 && x==n-1) return result;

            if (y>0   && !visited[y-1][x]) {
                q.push({safeness[y-1][x], y-1, x});
                visited[y-1][x] = 1;
            }
            if (y<n-1 && !visited[y+1][x]) {
                q.push({safeness[y+1][x], y+1, x});
                visited[y+1][x] = 1;
            }
            if (x>0   && !visited[y][x-1]) {
                q.push({safeness[y][x-1], y, x-1});
                visited[y][x-1] = 1;
            }
            if (x<n-1 && !visited[y][x+1]) {
                q.push({safeness[y][x+1], y, x+1});
                visited[y][x+1] = 1;
            }
        }

        // unable to reach [n-1, n-1]
        return 0;
    }

private:
    void buildSafeness(vector<vector<int>>& grid, vector<vector<int>>& safeness, int n) {
        vector<vector<char>> visited(n, vector<char>(n, 0));
        queue<array<int,2>> q;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1) {
                    safeness[i][j] = 0;
                    visited[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        int dist = 0;
        while (!q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                auto [y, x] = q.front();
                q.pop();
                safeness[y][x] = dist;

                if (y>0   && !visited[y-1][x]) { q.push({y-1, x}); visited[y-1][x]=1; }
                if (y<n-1 && !visited[y+1][x]) { q.push({y+1, x}); visited[y+1][x]=1; }
                if (x>0   && !visited[y][x-1]) { q.push({y, x-1}); visited[y][x-1]=1; }
                if (x<n-1 && !visited[y][x+1]) { q.push({y, x+1}); visited[y][x+1]=1; }
            }
            dist++;
        }
    }
};
