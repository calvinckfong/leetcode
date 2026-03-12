// 3600. Maximize Spanning Tree Stability with Upgrades
class Solution {
struct Edge{
    int u, v, w;
    int type;
};

class DSU {
public:
    vector<int> parent;

    DSU(const vector<int>& p) : parent(p) {}

    int find(int x) {
        return (parent[x]==x) ? x : (parent[x] = find(parent[x]));
    }

    void join(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[px] = py;
        }
    }
};

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        if (edges.size()<n-1) return -1;

        int nEdges = edges.size();
        vector<Edge> sortedEdges(nEdges);
        for (int i=0; i<nEdges; i++) {
            auto& e = edges[i];
            sortedEdges[i] = {e[0], e[1], e[2], e[3]};
        }

        vector<Edge> mustEdges, optionalEdges;
        for (const auto& e: sortedEdges) {
            if (e.type == 1) {
                mustEdges.push_back(e);
            } else {
                optionalEdges.push_back(e);
            }
        }

        if (mustEdges.size()>n-1) return -1;

        sort(optionalEdges.begin(), optionalEdges.end(), 
            [](const Edge& a, const Edge& b){
                return b.w < a.w;
            });

        int selected0 = 0;
        const int MAX_STABILITY = 2e5;
        int minStability = MAX_STABILITY;
        vector<int> initParent(n);
        iota(initParent.begin(), initParent.end(), 0);
        DSU dsu0(initParent);

        for (auto& e: mustEdges) {
            if (dsu0.find(e.u) == dsu0.find(e.v) || selected0==n-1) {
                 return -1;
            }

            dsu0.join(e.u, e.v);
            selected0++;
            minStability = min(minStability, e.w);
        }

        
        int l=0, r=minStability;
        int res;
        while (l<r) {
            int m = (l + r + 1)/2;
            DSU dsu(dsu0.parent);

            int selected = selected0;
            int dblCnt = 0;

            for (auto& e: optionalEdges) {
                if (dsu.find(e.u) == dsu.find(e.v)) continue;

                if (e.w >= m) {
                    dsu.join(e.u, e.v);
                    selected++;
                } else if (dblCnt<k && e.w*2>=m) {
                    dblCnt++;
                    dsu.join(e.u, e.v);
                    selected++;
                } else {
                    break;
                }

                if (selected==n-1) break;
            }

            if (selected != n-1) {
                r = m - 1;
            } else {
                res = m;
                l = m;
            }
        }
        return res;
    }
};
