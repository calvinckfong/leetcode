// 1976. Number of Ways to Arrive at Destination
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;

        vector<vector<pair<int, int>>> graph(n);
        for (auto& r: roads) {
            graph[r[0]].emplace_back(r[1], r[2]);
            graph[r[1]].emplace_back(r[0], r[2]);
        }

        vector<long long> shortestT(n, LLONG_MAX);
        shortestT[0] = 0;

        vector<int> pathCnt(n, 0);
        pathCnt[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long currTime = pq.top().first;
            int curr = pq.top().second;
           pq.pop();

           if (currTime > shortestT[curr]) continue;

           for (auto& [next, cost]: graph[curr]) 
           {
                if (currTime + cost < shortestT[next]) {
                    shortestT[next] = currTime + cost;
                    pathCnt[next] = pathCnt[curr];
                    pq.emplace(shortestT[next], next);
                }
                else if (currTime + cost == shortestT[next]) {
                    pathCnt[next] = 
                        (pathCnt[next] + pathCnt[curr]) % MOD;
                }
           }
        }

        return pathCnt[n-1];
    }
};
