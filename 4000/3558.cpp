// 3558. Number of Ways to Assign Edge Weights I
class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n+1);
        for (auto& e: edges) {
            int u = e[0], v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        int max_depth = dfs(g, 1, 0);
        return qpow(2, max_depth-1);
    }

private:
    int dfs(vector<vector<int>>& g, int x, int f) {
        int max_depth = 0;
        for (auto& y: g[x]) {
            if (y != f) {
                max_depth = max(max_depth, dfs(g, y, x)+1);
            }
        }
        return max_depth;
    }

    int qpow(int x, int y) {
        const int MOD = 1e9 + 7;
        int res = 1;
        for (; y; y>>=1) {
            if (y&1) {
                res = 1ll * res * x % MOD;
            }
            x = 1ll * x * x % MOD;
        }
        return res;
    }
};
