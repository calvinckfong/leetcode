// 2976. Minimum Cost to Convert String I
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int MAX_COST = 2000000;
        vector<vector<int>> graph(26, vector<int>(26, MAX_COST));
        for (int i=0; i<26; i++)
            graph[i][i] = 0;
        
        // Build graph
        for (int i=0; i<original.size(); i++) {
            int c1 = original[i]-'a';
            int c2 = changed[i]-'a'; 
            graph[c1][c2] = min(graph[c1][c2], cost[i]);
        }

        // Find min-distance
        for (int k=0; k<26; k++)
            for (int i=0; i<26; i++)
                for (int j=0; j<26; j++)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

        // compute total cost
        long long result = 0;
        for (int i=0; i<source.size(); i++) {
            int c = graph[source[i]-'a'][target[i]-'a'];
            if (c == MAX_COST) return -1;
            else result += c;
        }
        return result;
    }
};
