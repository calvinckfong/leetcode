// 3372. Maximize the Number of Target Nodes After Connecting Trees I
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        vector<int> count1 = build(edges1, n1, k);
        vector<int> count2 = build(edges2, n2, k-1);
        int maxCnt = *max_element(count2.begin(), count2.end());
        vector<int> result(n1);
        for (int i=0; i<n1; i++)
            result[i] = count1[i] + maxCnt;
        return result;
    }

private:
    vector<int> build(vector<vector<int>>& edges, int n, int k) {
        vector<vector<int>> children(n);
        for (const vector<int>& e: edges) {
            children[e[0]].push_back(e[1]);
            children[e[1]].push_back(e[0]);
        }
        vector<int> result(n);
        for (int i=0; i<n; i++)
            result[i] = dfs(i, -1, children, k);
        return result;
    }

    int dfs(int node, int parent, const vector<vector<int>>& children, int k) {
        if (k<0)    return 0;

        int result = 1;
        for (int c: children[node]) {
            if (c == parent)    continue;
            result += dfs(c, node, children, k-1);
        }
        return result;
    }
};
