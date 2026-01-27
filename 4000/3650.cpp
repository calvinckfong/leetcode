// 3650. Minimum Cost Path with Edge Reversals
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e: edges) {
            int x=e[0], y=e[1], w=e[2];
            graph[x].emplace_back(y, w);
            graph[y].emplace_back(x, 2*w);
        }

        vector<bool> v(n, false);
        vector<int> d(n, INT_MAX);
        d[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            greater<pair<int, int>>> q;
        q.emplace(0,0);

        while (!q.empty()) {
            int x = q.top().second;
            q.pop();

            if (x == n-1) {
                return d[x];
            }

            if (v[x]) continue;

            v[x] = 1;

            for (auto& [y, w]: graph[x]) {
                if (d[x]+w < d[y]) {
                    d[y] = d[x] + w;
                    q.emplace(d[y], y);
                }
            }
        }
        return -1;
    }
};
