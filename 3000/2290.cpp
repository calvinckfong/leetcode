// 2290. Minimum Obstacle Removal to Reach Corner
class Solution {
public:
    const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> minObs(m, vector<int>(n, INT_MAX));
        minObs[0][0] = 0;

        deque<vector<int>> dq;
        dq.push_front({0, 0, 0});
        while (!dq.empty()) {
            vector<int> curr = dq.front();
            dq.pop_front();

            int o=curr[0], r=curr[1], c=curr[2];
            for (int i=0; i<4; i++) {
                int next_r = r + dir[i][0];
                int next_c = c + dir[i][1];

                if (next_r>=0 && next_r<m && next_c>=0 && next_c<n 
                        && minObs[next_r][next_c]==INT_MAX) {
                    if (grid[next_r][next_c]) {
                        minObs[next_r][next_c] = o+1;
                        dq.push_back({o+1, next_r, next_c});
                    } else {
                        minObs[next_r][next_c] = o;
                        dq.push_front({o, next_r, next_c});
                    }
                }
            }
        }
        return minObs[m-1][n-1];
    }
};
