// 3203. Find Minimum Diameter After Merging Two Trees
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1 = buildAdj(edges1, n);
        vector<vector<int>> adj2 = buildAdj(edges2, m);

        int d1 = dfs(adj1, 0, -1).first;
        int d2 = dfs(adj2, 0, -1).first;

        int d3 = ceil(d1/2.0) + ceil(d2/2.0) + 1;

        return max({d1, d2, d3});
    }

private:
    vector<vector<int>> buildAdj(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n);
        for (vector<int>& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return adj;
    }
    
    pair<int, int> dfs(vector<vector<int>>& adj, int node, int parent) {
        int maxDepth1=0, maxDepth2=0;
        int diameter = 0;

        for (int next: adj[node]) {
            if (next == parent) continue;

            auto [nextDiameter, depth] = dfs(adj, next, node);

            diameter = max(diameter, nextDiameter);

            depth++;

            if (depth>maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = depth;
            } else if (depth>maxDepth2) {
                maxDepth2 = depth;
            }
        }

        diameter = max(diameter, maxDepth1+maxDepth2);

        return {diameter, maxDepth1};
    }
};
