// 3108. Minimum Cost Walk in Weighted Graph
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        adjList = vector<vector<pair<int, int>>>(n);
        for (auto e: edges) {
            adjList[e[0]].push_back({e[1], e[2]});
            adjList[e[1]].push_back({e[0], e[2]});
        }
        visited = vector<bool>(n);
        comp = vector<int>(n);

        int compId = 0;
        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                cost.push_back(getCost(i, compId));
                compId++;
            }
        }

        int nq = query.size();
        vector<int> result(nq, -1);
        for (int i=0; i<nq; i++) {
            int s = query[i][0];
            int e = query[i][1];
            if (comp[s] == comp[e]) {
                result[i] = cost[comp[s]];
            } 
        }
        return result;
    }

private:
    vector<vector<pair<int, int>>> adjList;
    vector<bool> visited;
    vector<int> comp;
    vector<int> cost;

    int getCost(int node, int compId) {
        int result = INT_MAX;
        comp[node] = compId;
        visited[node] = true;

        for (auto& [n, w]: adjList[node]) {
            result &= w;
            if (!visited[n]) {
                result &= getCost(n, compId);
            }
        }
        return result;
    }
};
