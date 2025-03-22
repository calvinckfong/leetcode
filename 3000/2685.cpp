// 2685. Count the Number of Complete Components
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int nEdges = edges.size();
        for (auto& e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int result = 0;
        for (int i=0; i<n; i++) {
            if (visited[i]) continue;

            int comp[2] = {0, 0};
            dfs(i, comp);

            if (comp[0] * (comp[0]-1) == comp[1])
                result++; 
        }
        return result;
    }

private:
    vector<int> graph[50];
    bool visited[50];

    void dfs(int node, int comp[2]) {
        visited[node] = true;
        comp[0]++;
        comp[1] += graph[node].size();

        for (int next: graph[node]) {
            if (!visited[next])
                dfs(next, comp);
        }
    }
};
