// 3373. Maximize the Number of Target Nodes After Connecting Trees II
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        vector<int> color1(n1+1);
        vector<int> color2(n2+1);
        vector<int> cnt1 = build(edges1, n1, color1);
        vector<int> cnt2 = build(edges2, n2, color2);
        vector<int> result(n1);
        int delta = max(cnt2[0], cnt2[1]);
        for (int i=0; i<n1; i++)
            result[i] = cnt1[color1[i]] + delta;
        return result;
    }

private:
    vector<int> build(vector<vector<int>>& edges, int n, vector<int>& color) {
        vector<vector<int>> children(n+1);
        for (const auto& e: edges) {
            children[e[0]].push_back(e[1]);
            children[e[1]].push_back(e[0]);
        }
        int result = dfs(0, -1, 0, children, color);
        return {result, n - result};
    }

    int dfs(int node, int parent, int depth, 
            const vector<vector<int>>& children, vector<int>& color) {
        int result = 1 - depth%2;
        color[node] = depth%2;
        for (int c: children[node]) {
            if (c == parent) continue;
            result += dfs(c, node, depth+1, children, color);
        }
        return result;
    }
};
