// 3970. Shortest Path With At Most K Consecutive Identical Characters
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e: edges) {
            g[e[0]].emplace_back(e[1], e[2]);
        }

        vector<vector<long long>> dis(n, vector<long long>(k+1, INT_MAX));
        priority_queue<tuple<long long, int , int>, 
            vector<tuple<long long, int, int>>, greater<>> pq;
        dis[0][1] = 0;
        pq.emplace(0, 0, 1);

        while (!pq.empty()) {
            auto [d, x, cnt] = pq.top();
            pq.pop();

            if (d>dis[x][cnt]) continue;
            if (x == n-1) return d;

            for (auto [y, w] : g[x]) {
                int new_cnt = (labels[x]==labels[y]) ? cnt+1 : 1;
                if (new_cnt > k) continue;

                long long new_d = d + w;
                if (new_d < dis[y][new_cnt]) {
                    dis[y][new_cnt] = new_d;
                    pq.emplace(new_d, y, new_cnt);
                }
            }
        }
        return -1;
    }
};
