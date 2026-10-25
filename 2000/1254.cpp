// 1254. Number of Closed Islands
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        visit = vector<vector<bool>>(m, vector<bool>(n));
        
        int res = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==0 && !visit[i][j]) {
                    res += bfs(i, j, grid);
                }
            }
        }
        return res;
    }

private:
    int m, n;
    vector<vector<bool>> visit;

    bool bfs(int x, int y, vector<vector<int>>& grid) {
        const int DIRS[5] = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({x, y});
        visit[x][y] = 2;
        bool isClosed = true;

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for (int d=0; d<4; d++) {
                int r = x + DIRS[d];
                int c = y + DIRS[d+1];
                if (r<0 || r>=m || c<0 || c>=n) 
                {
                    isClosed = false;
                } 
                else if (grid[r][c]==0 && !visit[r][c]) 
                {
                    q.push({r, c});
                    visit[r][c] = true;
                }
            }
        }
        return isClosed;
    }
};
