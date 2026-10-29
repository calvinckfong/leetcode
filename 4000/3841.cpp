// 3841. Palindromic Path Queries in a Tree
class BIT {
public:
    BIT(int _n) : n(_n), tree(_n+1) {}

    int query(int x) {
        int ret = 0;
        while (x) {
            ret ^= tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void updateRange(int l, int r, int v) {
        update(l, v);
        update(r+1, v);
    }
private:
    int n;
    vector<int> tree;
    static int lowbit(int x) { return x&-x; }
    
    void update(int x, int v) {
        while (x<=n) {
            tree[x] ^= v;
            x += lowbit(x);
        }
    }
};

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        dep = vector<int>(n);
        l = vector<int>(n);
        r = vector<int>(n);
        LOG = 32 - __builtin_clz(n);
        fa = vector<vector<int>>(n, vector<int>(LOG));
        g = vector<vector<int>>(n);
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs(0, 0);

        for (int i=1; i<LOG; i++) {
            for (int j=0; j<n; j++) {
                fa[j][i] = fa[fa[j][i-1]][i-1];
            }
        }

        BIT bit(n+1);
        for (int i=0; i<n; i++) {
            bit.updateRange(l[i], r[i], 1<<(s[i]-'a'));
        }

        vector<bool> res;
        for (string& q: queries) {
            stringstream ss(q);
            string op;
            ss >> op;
            if (op == "update") {
                int u;
                char c;
                ss >> u >> c;
                bit.updateRange(l[u], r[u], (1<<(s[u]-'a'))^(1<<(c-'a')));
                s[u] = c;
            } else {
                int u, v;
                ss >> u >> v;
                int w = lca(u, v);
                int mask = bit.query(l[u]);
                mask ^= bit.query(l[v]);
                mask ^= (1<<(s[w]-'a'));
                res.push_back(__builtin_popcount(mask)<=1);
            }
        }
        return res;
    }

private:
    int LOG = 0;
    int timer = 0;
    vector<int> dep, l, r;
    vector<vector<int>> fa, g;

    void dfs(int u, int p) {
        l[u] = ++timer;
        fa[u][0] = p;
        for (int i : g[u]) {
            if (i==p) continue;
            dep[i] = dep[u] + 1;
            dfs(i, u);
        }
        r[u] = timer;
    }

    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);

        int diff = dep[u] - dep[v];
        for (int i=0; i<LOG; i++) {
            if ((diff>>i) & 1) u = fa[u][i];
        }
        if (u==v) return u;

        for (int i=LOG-1; i>=0; i--) {
            if (fa[u][i] != fa[v][i]) {
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    }
};
