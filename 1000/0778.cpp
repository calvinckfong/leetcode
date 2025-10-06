// 778. Swim in Rising Water
class Solution {
public:
    struct T {
        int t, x, y;
        T(int _t, int _x, int _y) : t(_t), x(_x), y(_y) {}
        bool operator< (const T &other) const {
            return t > other.t;
        }
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        const int dirs[5] = {-1, 0, 1, 0, -1};
        vector<vector<int>> seen(n, vector<int>(n, 0));
        seen[0][0] = 1;

        priority_queue<T> pq;
        pq.push(T(grid[0][0], 0, 0));
        int res = 0;
        while (!pq.empty()) {
            T p = pq.top();
            pq.pop();
            res = max(res, p.t);
            if (p.x==n-1 && p.y==n-1) break;
            for (int i=0; i<4; i++) {
                int nx = p.x + dirs[i];
                int ny = p.y + dirs[i+1];
                if (nx>=0 && nx<n && ny>=0 && ny<n && !seen[nx][ny]) {
                    seen[nx][ny] = 1;
                    pq.push(T(grid[nx][ny], nx, ny));
                }
            }
        }
        return res;
    }
};
