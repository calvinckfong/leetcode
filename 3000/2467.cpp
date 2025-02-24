// 2467. Most Profitable Path in a Tree
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        n = amount.size();
        graph.resize(n, vector<int>());
        dist.resize(n);
        for (auto e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return solve(0, 0, 0, bob, amount);
    }

private:
    int n;
    vector<vector<int>> graph;
    vector<int> dist;

    int solve(int src, int parent, int time, int bob, vector<int>& amount) {
        int maxIncome=0, maxChild=INT_MIN;

        dist[src] = (src == bob)?0:n;
        for (int adj : graph[src]) {
            if (adj != parent) {
                maxChild = max(maxChild, solve(adj, src, time+1, bob, amount));
                dist[src] = min(dist[src], dist[adj]+1);
            }
        }

        if (dist[src]>time) 
            maxIncome += amount[src];
        else if (dist[src] == time)
            maxIncome += amount[src]/2;

        return (maxChild==INT_MIN)?maxIncome:maxIncome+maxChild;
    }
};
