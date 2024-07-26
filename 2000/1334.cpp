// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int MAX_DIST = 10001;
        vector<vector<int>> dist(n, vector<int>(n, MAX_DIST));
        for (int i=0; i<edges.size(); i++) {
            int c1 = edges[i][0], c2 = edges[i][1];
            dist[c1][c2] = dist[c2][c1] = edges[i][2];
        }

        for (int i=0; i<n; i++) dist[i][i] = 0;
        
        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        int result = 0, leastConnect = 100;
        for (int i=0; i<n; i++) {
            int connectCnt = 0;
            for (int j=0; j<n; j++)
                connectCnt += (dist[i][j] <= distanceThreshold);
            if (connectCnt <= leastConnect) {
                result = i;
                leastConnect = connectCnt;
            }
        }
        return result;
    }
};
