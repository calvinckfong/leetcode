// 947. Most Stones Removed with Same Row or Column
class UnionFind {
public:
    vector<int> parent;
    int count;
    unordered_set<int> uniqueNodes;

    UnionFind(int n) {
        parent.resize(n, -1);
        count = 0;
    }

    int find(int node) {
        if (uniqueNodes.find(node) == uniqueNodes.end()) {
            count++;
            uniqueNodes.insert(node);
        }

        if (parent[node] == -1) return node;

        return parent[node] = find(parent[node]);
    }

    void unionNodes(int n1, int n2) {
        int r1 = find(n1);
        int r2 = find(n2);

        if (r1 == r2) return;

        parent[r1] = r2;
        count--;
    } 
};

class Solution {
public:
    const int maxN = 10001;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(2*maxN);

        for (int i=0; i<n; i++) {
            uf.unionNodes(
                stones[i][0],
                stones[i][1] + maxN
            );
        }

        return n - uf.count;
    }
};
