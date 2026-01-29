// 2976. Minimum Cost to Convert String I
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int m = cost.size();
        int n = source.size();
        vector<vector<int>> graph(26, vector<int>(26, INT_MAX));
        for (int i=0; i<26; i++) graph[i][i] = 0;

        long long res = 0;
        for (int i=0; i<m; i++) {
            int src = original[i]-'a';
            int dst = changed[i]-'a';
            graph[src][dst] = min(graph[src][dst], cost[i]);
        }

        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                if (graph[j][i] != INT_MAX) {
                    for (int k=0; k<26; k++) {
                        if (graph[i][k] != INT_MAX) {
                            graph[j][k] = min(graph[j][k], graph[j][i]+graph[i][k]);
                        }
                    }
                }
            }
        }

        for (int i=0; i<n; i++) {
            if (source[i]==target[i]) continue;
            else {
                int src = source[i]-'a';
                int dst = target[i]-'a';
                if (graph[src][dst]==INT_MAX) return -1;
                res += graph[src][dst];
            }
        }

        return res;
    }
};
