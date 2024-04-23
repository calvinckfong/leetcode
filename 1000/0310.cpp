// 310. Minimum Height Trees
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> result;
        // Fast-stop for n<=2
        if (n<=2) {
            for (int i=0; i<n; i++) result.push_back(i);
            return result;
        }

        // Build adjacent graph and degree of each node
        vector<vector<int>> adj_graph(n);
        vector<int> degree(n, 0);
        for (vector<int> e: edges) {
            adj_graph[e[0]].push_back(e[1]);
            adj_graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        // Queue for degree=1
        queue<int> q;
        for (int i=0; i<degree.size(); i++) {
            if (degree[i]==1) {
                q.push(i);
                result.push_back(i);
            }
        }

        // BFS
        while (!q.empty()) {
            int qSize = q.size();
            result.clear();
            while (qSize--) {
                int node = q.front();
                result.push_back(node);
                q.pop();
                degree[node]--;
                for (int adj_node: adj_graph[node]) {
                    degree[adj_node]--;
                    if (degree[adj_node] == 1) q.push(adj_node);
                }
            }
        }
        return result;
    }
};
