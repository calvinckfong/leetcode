// 1857. Largest Color Value in a Directed Graph
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        unordered_map<int, vector<int>> graph;
        vector<int> degree(n);
        for (auto& e: edges) {
            graph[e[0]].push_back(e[1]);
            degree[e[1]]++;
        }

        vector<array<int, 26>> freq(n);
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (degree[i]==0) {
                q.push(i);
                freq[i][colors[i]-'a'] = 1;
            }
        }

        int result = 0, seen = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int val = *max_element(freq[i].begin(), freq[i].end());
            result = max(result, val);
            seen++;
            for (int j: graph[i]) {
                for (int k=0; k<26; k++) {
                    freq[j][k] = max(freq[j][k], freq[i][k] + (k == colors[j]-'a'));
                }
                if (--degree[j]==0)   q.push(j);
            }
        }
        return (seen < n) ? -1 : result;
    }
};
