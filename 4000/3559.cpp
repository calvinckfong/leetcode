// 3559. Number of Ways to Assign Edge Weights II
class LCA {
public: 
    LCA(vector<vector<int>>& edges, const int root) {
        n = edges.size() + 1;
        m = 32 - __builtin_clz(n);
        _e.resize(n+1);
        _d.resize(n+1);
        _f.resize(n+1, vector<int>(m, 0));

        for (auto& e: edges) {
            int u = e[0], v = e[1];
            _e[u].push_back(v);
            _e[v].push_back(u);
        }

        dfs(root, 0);

        for (int i=1; i<m; i++) {
            for (int x=1; x<=n; x++) {
                _f[x][i] = _f[_f[x][i-1]][i-1];
            }
        }
    }

    int dist(int x, int y) {
        return _d[x] + _d[y] - 2*_d[lca(x, y)];
    }
private:
    int m, n;
    vector<vector<int>> _e;
    vector<int> _d;
    vector<vector<int>> _f;

    void dfs(int x, int target) {
        _f[x][0] = target;
        for (auto& y: _e[x]) {
            if (y != target) {
                _d[y] = _d[x] + 1;
                dfs(y, x);
            }
        }
    }

    int lca(int x, int y) {
        if (_d[x] > _d[y]) {
            swap(x, y);
        }
        for (int i=m-1; i>=0; i--) {
            if (_d[x] <= _d[_f[y][i]]) {
                y = _f[y][i];
            }
        }

        if (x == y) return x;

        for (int i=m-1; i>=0; i--) {
            if (_f[y][i] != _f[x][i]) {
                x = _f[x][i];
                y = _f[y][i];
            }
        }
        return _f[x][0];
    }
};

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        initLookup();
        LCA lca(edges, 1);
        int nq = queries.size();
        vector<int> res(nq);
        for (int i=0; i<nq; i++) {
            int x = queries[i][0], y = queries[i][1];
            if (x != y) {
                res[i] = lookup[lca.dist(x, y) - 1];
            }
        }
        return res;
    }    

private:
    const int MOD = 1e9 + 7;
    static const int N = 100010;
    int lookup[N];
    void initLookup() {
        lookup[0] = 1;
        for (int i=1; i<N; i++) {
            lookup[i] = (lookup[i-1]*2) % MOD;
        }
    }
};
