// 2577. Minimum Time to Visit a Cell In a Grid
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // early stop
        if (grid[0][1]>1 && grid[1][0]>1) return -1;

        const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int time=curr[0], r=curr[1], c=curr[2];

            if (r==m-1 && c==n-1) return time;

            if (visited[r][c]) continue;
            visited[r][c] = true;

            for (int i=0; i<4; i++) {
                int next_r = r + dir[i][0];
                int next_c = c + dir[i][1];
                if (next_r>=0 && next_r<m && next_c>=0 && next_c<n &&
                        !visited[next_r][next_c]) {
                    int wait = 1 - ((grid[next_r][next_c] - time) % 2);
                    int next_t = max(grid[next_r][next_c]+wait, time+1);
                    pq.push({next_t, next_r, next_c});
                }
            }
        }
        return -1;
    }
};
