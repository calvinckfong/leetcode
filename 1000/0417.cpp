// 417. Pacific Atlantic Water Flow
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m));
        vector<vector<bool>> atl(n, vector<bool>(m));

        queue<pair<int, int>> q;
        
        for (int i=0; i<n; i++) q.push({i,0});
        for (int i=0; i<m; i++) q.push({0,i});
        bfs(q, pac, heights);

        for (int i=0; i<n; i++) q.push({i, m-1});
        for (int i=0; i<m; i++) q.push({n-1, i});
        bfs(q, atl, heights);

        vector<vector<int>> res;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (pac[i][j] && atl[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }

private:
    int n, m;
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& vis, vector<vector<int>>& heights)
    {
        const int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vis[r][c] = true;

            for (int i=0; i<4; i++) {
                int nr = r + dirs[i];
                int nc = c + dirs[i+1];
                if (nc>=0 && nc<m && nr>=0 && nr<n &&
                        heights[r][c] <= heights[nr][nc] && !vis[nr][nc]) {
                    q.push({nr, nc});
                }
            }
        }
    }
};
