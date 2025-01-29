// 684. Redundant Connection
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        visited = vector<bool>(n);
        parent = vector<int>(n, -1);
        adjList = vector<vector<int>>(n);

        for (auto e: edges) {
            adjList[e[0]-1].push_back(e[1]-1);
            adjList[e[1]-1].push_back(e[0]-1);
        }

        dfs(0);

        unordered_map<int, int> cycleNodes;
        int curr = cycleStart;
        do {
            cycleNodes[curr] = 1;
            curr = parent[curr];
        } while (curr != cycleStart);

        for (int i=n-1; i>=0; i--) {
            if (cycleNodes[edges[i][0]-1] && cycleNodes[edges[i][1]-1]) return edges[i];
        }

        return {};
    }

private:
    int cycleStart = -1;
    vector<bool> visited;
    vector<int> parent;
    vector<vector<int>> adjList;

    void dfs(int src) {
        visited[src] = true;

        for (int adj: adjList[src]) {
            if (!visited[adj]) {
                parent[adj] = src;
                dfs(adj);
            } else if (adj != parent[src] && cycleStart == -1) {
                cycleStart = adj;
                parent[adj] = src;
            }
        }
    }
};
