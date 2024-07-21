// 2392. Build a Matrix With Conditions
class Solution {
public:
    // Kahn's Algorithm
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topSort(rowConditions, k);
        vector<int> colOrder = topSort(colConditions, k);

        // No solution
        printf("%d %d\n", rowOrder.size(), colOrder.size());
        if (rowOrder.empty() || colOrder.empty()) return {};
    
        // construct result
        vector<vector<int>> result(k, vector<int>(k, 0));
        for (int i=0; i<k; i++) {
            for (int j=0; j<k; j++) {
                if (rowOrder[i] == colOrder[j])
                    result[i][j] = rowOrder[i];
            }
        }
        return result;
    }

private:
    vector<int> topSort(vector<vector<int>>& cond, int k) {
        vector<vector<int>> adj(k+1);
        vector<int> deg(k+1), order;

        for (auto x: cond) {
            adj[x[0]].push_back(x[1]);  
            deg[x[1]]++;
        }

        queue<int> q;
        for (int i=1; i<=k; i++)
            if (deg[i]==0)  q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            k--;
            for (int adjNode : adj[node])
                if (--deg[adjNode]==0) q.push(adjNode);
        }

        if (k!=0) return {};
        return order;
    }
};
