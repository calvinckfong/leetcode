// 1514. Path with Maximum Probability
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<double, int>> neighbours[n];

        for (int i=0; i<edges.size(); i++) {
            int s = edges[i][0];
            int e = edges[i][1];
            neighbours[s].push_back({succProb[i], e});
            neighbours[e].push_back({succProb[i], s});
        }

        vector<double> maxProb(n, -1.0);
        maxProb[start] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            for (auto& p: neighbours[curr.second]) {
                double next_prob = p.first;
                int next_node = p.second;
                // printf("%d %f\n", next_node, next_prob);
                if (curr.first*next_prob > maxProb[next_node]) {
                    maxProb[next_node] = curr.first*next_prob;
                    pq.push({maxProb[next_node], next_node});
                }
            }
        }
        if (maxProb[end]<0) return 0.0;
        else return maxProb[end];
    }
};
