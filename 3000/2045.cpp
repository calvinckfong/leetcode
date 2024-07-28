// 2045. Second Minimum Time to Reach Destination
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Adjacency matrix
        vector<vector<int>> adj(n+1);
        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // bfs
        queue<pair<int, int>> q;
        q.push({1, 1}); // node, freq

        vector<int> dist1(n+1, -1);
        vector<int> dist2(n+1, -1);
        dist1[1] = 0;
        while (!q.empty()) {
            auto [node, freq] = q.front();
            q.pop();

            int t = (freq==1)?dist1[node]:dist2[node];

            if ((t/change)%2) {
                // red light
                t = change * (1 + t/change) + time;
            } else {
                // gree light
                t += time; 
            }

            for (int neighbour: adj[node]) {
                if (dist1[neighbour]==-1) {
                    dist1[neighbour] = t;
                    q.push({neighbour, 1});
                } else if (dist2[neighbour]==-1 && dist1[neighbour]!=t) {
                    if (neighbour==n) return t; // second minimum
                    dist2[neighbour] = t;
                    q.push({neighbour, 2});
                }
            }
        }
        // cannot reach node n;
        return 0;
    }
};
