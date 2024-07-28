// 1466. Reorder Routes to Make All Paths Lead to the City Zero
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // adjacent matrix
        vector<vector<pair<int, int>>> adj(n);  // node, dir
        for (vector<int> c: connections) {
            adj[c[0]].push_back({c[1], 1});
            adj[c[1]].push_back({c[0], 0});
        }

        count = 0;
        solve(0, n, adj);
        return count;
    }

private:
    int count;
    // bfs
    void solve(int node, int n, vector<vector<pair<int, int>>>& adj) {
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            node = q.front(); q.pop();
            for (auto& [neighbour, dir]: adj[node]) {
                // flip all unvisited nodes
                if (!visited[neighbour]) {
                    count += dir;
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
};
