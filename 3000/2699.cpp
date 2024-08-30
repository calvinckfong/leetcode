// 2699. Modify Graph Edge Weights
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int dest, int target) {
        
        // build graph
        vector<vector<pair<int, int>>> neigh(n);
        for (auto e: edges) {
            if (e[2] != -1) {
                neigh[e[0]].emplace_back(e[1], e[2]);
                neigh[e[1]].emplace_back(e[0], e[2]);
            }
        }

        // find shortest path
        int minDist = dijkstra(n, source, dest, neigh);
        if (minDist == target) {
            for (auto& e: edges) {
                if (e[2] == -1) e[2] = target;
            }
            return edges;
        } 
        else if (minDist < target) 
            return {};

        // adjust weights
        bool match = false;
        for (int i=0; i<edges.size(); i++) {
            auto& e = edges[i];
            if (e[2] != -1) continue;

            e[2] = 1;
            neigh[e[0]].emplace_back(e[1], 1);
            neigh[e[1]].emplace_back(e[0], 1);

            int dist = dijkstra(n, source, dest, neigh);
            if (dist <= target) {
                e[2] += (target - dist);
                for (int j=i+1; j<edges.size(); j++)
                {
                    if (edges[j][2] == -1)  edges[j][2] = target;
                }
                return edges;
            }

        }
        return {};
    }

private:
    int dijkstra(int n, int src, int dest, const vector<vector<pair<int, int>>>& graph) {
        vector<int> minDist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> mh;

        minDist[src] = 0;
        mh.push({0, src});

        while (!mh.empty()) {
            auto [dist, u] = mh.top();
            mh.pop();

            if (dist > minDist[u]) continue;

            for (const auto& [v, w]: graph[u]) {
                if (dist+w < minDist[v]) {
                    minDist[v] = dist+w;
                    mh.push({minDist[v], v});
                }
            }
        }
        return minDist[dest];
    }
};
