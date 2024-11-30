// 2097. Valid Arrangement of Pairs
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // build direct graph
        unordered_map<int, int> inDeg, outDeg;
        for (auto& p: pairs) {
            int start = p[0], end = p[1];
            adjMatrix[start].push_back(end);
            inDeg[end]++;
            outDeg[start]++;
        }

        // find start node
        int startNode = -1;
        for (auto& p: outDeg) {
            int node = p.first;
            if (outDeg[node] == inDeg[node]+1) {
                startNode = node;
                break;
            }
        }
        // it is a loop.  start from first element
        if (startNode==-1) startNode = pairs[0][0];

        // find a path passing all nodes
        dfs(startNode);

        // construct output
        vector<vector<int>> result;
        for (int i=path.size()-2; i>=0; i--) {
            result.push_back({path[i+1], path[i]});
        }
        return result;
    }

private:
    unordered_map<int, deque<int>> adjMatrix;
    vector<int> path;
    void dfs(int node) {
        while (!adjMatrix[node].empty()) {
            int next = adjMatrix[node].front();
            adjMatrix[node].pop_front();
            dfs(next);
        }
        path.push_back(node);
    }
};
