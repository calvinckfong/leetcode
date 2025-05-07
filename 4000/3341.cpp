// 3341. Find Minimum Time to Reach Last Room I

class State {
public:
    int x;
    int y;
    int dis;
    State(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int maxCost = 0x3fffffff;
        const int dirs[5] = {-1, 0, 1, 0, -1};
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>> costs(m, vector<int>(n, maxCost));
        vector<vector<int>> visited(m, vector<int>(n, 0));

        costs[0][0] = 0;

        auto cmp = [](const State& a, const State& b) { return a.dis > b.dis; };

        priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
        pq.push(State(0, 0, 0));

        while (!pq.empty()) {
            State s = pq.top();
            pq.pop();
            if (visited[s.x][s.y]) continue;
            visited[s.x][s.y] = 1;

            for (int i = 0; i < 4; i++) {
                int nx = s.x + dirs[i];
                int ny = s.y + dirs[i+1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                int dist = max(costs[s.x][s.y], moveTime[nx][ny]) + 1;
                if (costs[nx][ny] > dist) {
                    costs[nx][ny] = dist;
                    pq.push(State(nx, ny, dist));
                }
            }
        }

        return costs[m - 1][n - 1];
    }
};
