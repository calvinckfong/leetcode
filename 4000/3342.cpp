// 3342. Find Minimum Time to Reach Last Room II
class State {
public:
    int x, y, cost;
    State(int x, int y, int cost) : x(x), y(y), cost(cost) {}
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int maxCost = 0x3fffffff;
        const int dirs[] = {-1, 0, 1, 0, -1};
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>> cost(m, vector<int>(n, maxCost));
        vector<vector<bool>> visit(m, vector<bool>(n, false));

        cost[0][0] = 0;
        auto cmp = [](const State& a, const State& b) { return a.cost > b.cost; };
        priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
        pq.push(State(0,0,0));

        while (!pq.empty()) {
            State s = pq.top();
            pq.pop();
            if (visit[s.y][s.x]) continue;
            if (s.y==m-1 && s.x==n-1) break;

            visit[s.y][s.x] = true;
            for (int d = 0; d<4; d++) {
                int nx = s.x + dirs[d];
                int ny = s.y + dirs[d+1];
                if (nx<0 || ny<0 || nx>=n || ny>=m ) continue;
                if (visit[ny][nx]) continue;

                int c = max(cost[s.y][s.x], moveTime[ny][nx]) + (s.x + s.y)%2 + 1;
                if (cost[ny][nx] > c) {
                    cost[ny][nx] = c;
                    pq.push(State(nx, ny, c));
                }    
            }
        }
        return cost[m-1][n-1];
    }
};
