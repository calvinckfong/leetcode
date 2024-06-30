// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
class UnionFind {
public:
    vector<int> parent;
    int nGroup;

    UnionFind(int size) : parent(size), nGroup(size) {
        for (int i=0; i<size; i++) parent[i] = i;
    }

    int add(int n1, int n2) {
        if (find(n1) == find(n2)) return 0; // same union/parent, no edge added
        parent[find(n1)] = n2; // join 2 groups
        nGroup--; // two groups join. reduce group number by 1
        return 1; // new edge is added
    }

    // one can traverse iff there is 1 group only, i.e. all nodes are connected
    bool canTraverse() { return nGroup==1; }

private:
    int find(int n) {
        return parent[n] = (parent[n]==n) ? n : find(parent[n]);
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Sort edges by type in descending order
        sort(edges.begin(), edges.end(), [](vector<int>&a, vector<int>&b){
            return a[0]>b[0];
        });

        int edgeAdded = 0; // number of edges added
        // Add edges to Alice's and Bob's union-find
        UnionFind Alice(n), Bob(n);
        for (int i=0; i<edges.size(); i++) {
            int n1 = edges[i][1]-1, n2 = edges[i][2]-1; // convert from 1-index to 0-index
            switch (edges[i][0]) {
            case 3: // both
                // use bitwise-or '|' so that both Alice.add() and Bob.add will be run
                edgeAdded += (Alice.add(n1, n2) | Bob.add(n1, n2));
                break;
            case 2: // bob
                edgeAdded += Bob.add(n1, n2);
                break;
            case 1: // alice
                edgeAdded += Alice.add(n1, n2);
                break;
            default:
                break;
            }
        }

        return (Alice.canTraverse() && Bob.canTraverse()) ? 
            edges.size()-edgeAdded : -1;
    }
};
