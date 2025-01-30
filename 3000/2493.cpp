// 2493. Divide Nodes Into the Maximum Number of Groups
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        adjList = vector<vector<int>>(n);
        parent = vector<int>(n, -1);
        depth = vector<int>(n);

        for (auto e: edges) {
            adjList[e[0]-1].push_back(e[1]-1);
            adjList[e[1]-1].push_back(e[0]-1);
            Union(e[0]-1, e[1]-1);
        }

        unordered_map<int, int> nGroupsOfComp;

        for (int i=0; i<n; i++) {
            int nGroup = getNGroup(i, n);
            if (nGroup == -1) return -1;
            int root = findRoot(i);
            nGroupsOfComp[root] = max(nGroupsOfComp[root], nGroup);
        }

        int result = 0;
        for (auto [root, nGroup] : nGroupsOfComp) {
            result += nGroup;
        }
        return result;
    }

private:
    vector<vector<int>> adjList;
    vector<int> parent;
    vector<int> depth;

    void Union(int n1, int n2) {
        n1 = findRoot(n1);
        n2 = findRoot(n2);

        if (n1 == n2) return;

        if (depth[n1] < depth[n2]) swap(n1, n2);
        parent[n2] = n1;

        if (depth[n1] == depth[n2]) depth[n1]++;
    }

    int findRoot(int node) {
        while (parent[node] != -1) node = parent[node];
        return node;
    }

    int getNGroup(int srcNode, int n) {
        queue<int> q;
        vector<int> layers(n, -1);
        q.push(srcNode);
        layers[srcNode] = 0;
        int deepestLayer = 0;

        while (!q.empty()) {
            int nNode = q.size();
            for (int i=0; i<nNode; i++) {
                int curr = q.front();
                q.pop();
                for (int next: adjList[curr]) {
                    if (layers[next] == -1) {
                        layers[next] = deepestLayer + 1;
                        q.push(next);
                    } else {
                        if (layers[next] == deepestLayer)
                            return -1;
                    }
                }
            }
            deepestLayer++;
        }
        return deepestLayer;
    }
};
