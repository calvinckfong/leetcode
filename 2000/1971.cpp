// 1971. Find if Path Exists in Graph
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        queue<int> newNodes;
        newNodes.push(source);
        while (!newNodes.empty()) {
            int qSize = newNodes.size();
            for (int i=0; i<qSize; i++) {
                int node = newNodes.front(); 
                newNodes.pop();
                for (int j=0; j<edges.size(); j++) {
                    if (edges[j][0]<0) continue;
                    if (edges[j][0] == node) {
                        if (edges[j][1] == destination) return true;
                        newNodes.push(edges[j][1]);
                        edges[j] = {-1, -1};
                    } else if (edges[j][1] == node) {
                        if (edges[j][0] == destination) return true;
                        newNodes.push(edges[j][0]);
                        edges[j] = {-1, -1};
                    }
                }
            }
        }
        return false;
    }
};
