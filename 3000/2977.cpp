// 2977. Minimum Cost to Convert String II
class Trie {
public:
    int id;
    Trie* children[26];

    Trie() : id(-1) {
        for (int i=0; i<26; i++) children[i] = nullptr;
    }
};

int add(Trie* node, const string& w, int& index) {
    for (char c: w) {
        int i = c - 'a';
        if (!node->children[i]) {
            node->children[i] = new Trie();
        }
        node = node->children[i];
    }
    if (node->id == -1) node->id = ++index;
    return node->id;
}

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const int INF = INT_MAX/2;
        int m = original.size();
        int n = source.size();
        
        vector<vector<int>> g(m*2, vector<int>(m*2, INF));
        for (int i=0; i<m*2; i++)   g[i][i] = 0;

        int p = -1;
        Trie* root = new Trie();
        for (int i=0; i<m; i++) {
            int s = add(root, original[i], p);
            int t = add(root, changed[i], p);
            g[s][t] = min(g[s][t], cost[i]);
        }

        for (int k=0; k<=p; k++) {
            for (int i=0; i<=p; i++) {
                for (int j=0;j<=p; j++) {
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                }
            }
        }

        auto update = [](long long& x, long long y) {
            if (x==-1 || y<x) x = y;
        };

        vector<long long> f(n, -1);
        for (int i=0; i<n; i++) {
            if (i>0 && f[i-1]==-1) continue;
            long long b = (i==0)?0:f[i-1];
            if (source[i]==target[i])
                update(f[i], b);
            
            Trie *u = root, *v = root;
            for (int j=i; j<n; j++) {
                u = u->children[source[j]-'a'];
                v = v->children[target[j]-'a'];
                if (!u || !v) break;
                if (u->id!=-1 && v->id!=-1) {
                    if (g[u->id][v->id] != INF) {
                        update(f[j], b+g[u->id][v->id]);
                    }
                }
            }
        }
        return f[n-1];
    }
};
