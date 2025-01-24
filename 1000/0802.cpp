// 802. Find Eventual Safe States
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        visit = vector<bool>(n);
        inStack = vector<bool>(n);

        for (int i=0; i<n; i++)
            dfs(i, graph);

        vector<int> result;
        for(int i=0; i<n; i++) {
            if (!inStack[i])
                result.push_back(i);
        }

        return result;
    }

private:
    vector<bool> visit, inStack;

    bool dfs(int node, vector<vector<int>>& graph) {
        if (inStack[node]) return true;
        if (visit[node]) return false;

        inStack[node] = visit[node] = true;
        for (auto next: graph[node]) {
            if (dfs(next, graph)) return true;
        }

        inStack[node] = false;
        return false;
    }
};
