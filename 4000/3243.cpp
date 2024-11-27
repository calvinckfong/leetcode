// 3243. Shortest Distance After Road Addition Queries I
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int nq = queries.size();
        vector<int> result(nq);
        vector<int> adj[500];

        for (int i=0; i<n; i++) {
            adj[i].push_back(i+1);
        }

        for (int i=0; i<nq; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            adj[u].push_back(v);

            result[i] = solve(n, adj);
        }
        return result;
    }

private:
    int solve(int n, vector<int> adj[]) {
        bool visited[500] = {false};
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int nodeCnt=1, nextNodeCnt=0;
        int depth = 0;

        while (!q.empty()) {
            for (int i=0; i<nodeCnt; i++) {
                int curr = q.front();
                q.pop();

                if (curr >= n-1) return depth;

                for (auto next: adj[curr]) {
                    if (visited[next]) continue;
                    q.push(next);
                    nextNodeCnt++;
                    visited[next] = true;
                }
            }

            nodeCnt = nextNodeCnt;
            nextNodeCnt = 0;
            depth++;
        }
        return -1;
    }
};
