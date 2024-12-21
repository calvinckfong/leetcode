// 2872. Maximum Number of K-Divisible Components
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj = vector<vector<int>>(n);
        for (vector<int>& e: edges) {
            int n1 = e[0];
            int n2 = e[1];
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }

        int result = 0;
        dfs_sum(0, -1, values, k, result);
        return result;
    }

private:
    vector<vector<int>> adj;
    int dfs_sum(int curr, int parent, vector<int>& values, int k, int& nGroup) {
        int sum = 0;
        for (int next: adj[curr]) {
            if (next != parent) {
                sum += dfs_sum(next, curr, values, k, nGroup);
                sum %= k;
            }
        }
        sum += values[curr];
        sum %= k;
        if (sum == 0) nGroup++;
        return sum;
    }
};
