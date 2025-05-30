// 2359. Find Closest Node to Given Two Nodes
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        vector<bool> visit1(n), visit2(n);
        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(node1, edges, dist1, visit1);
        dfs(node2, edges, dist2, visit2);

        int minDistNode = -1, minDist = INT_MAX;
        for (int i=0; i<n; i++) {
            int dist = max(dist1[i], dist2[i]);
            if (minDist > dist) {
                minDistNode = i;
                minDist = dist;
            }
        }
        return minDistNode;
    }

private:
    void dfs(int node, vector<int>& edges, vector<int>& dist, vector<bool>& visit) {
        visit[node] = true;
        int next = edges[node];
        if (next!=-1 && !visit[next]) {
            dist[next] = dist[node] + 1;
            dfs(next, edges, dist, visit);
        }
    }
};
