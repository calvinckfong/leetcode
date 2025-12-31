// 1970. Last Day Where You Can Still Cross
class Solution {
public:
    bool isPossible(int m, int n, int t, vector<vector<int>>& cells) {
        vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0));
        const int dirs[5] = {-1, 0, 1, 0, -1};

        for (int i = 0; i < t; i++) {
            grid[cells[i][0]][cells[i][1]] = 1;
        }

        queue<pair<int, int>> q;
        
        for (int i = 1; i <= n; i++) {
            if (grid[1][i] == 0) {
                q.push({1, i});
                grid[1][i] = 1;
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                int nr = r + dirs[i];
                int nc = c + dirs[i+1]; 
                if (nr > 0 && nc > 0 && nr <= m && nc <= n && grid[nr][nc] == 0) {
                    if (nr == m) return true; 
                    grid[nr][nc] = 1;                   
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = row * col, res = 0;
        while (left < right - 1) {
            int mid = left + (right - left) / 2;
            if (isPossible(row, col, mid, cells)) {
                left = mid;
                res = mid;
            } else {
                right = mid;
            }
        }
        return res;
    }
};
