// 787. Cheapest Flights Within K Stops
class Solution { 
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    { 
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:flights) { 
            adj[x[0]].push_back({x[1], x[2]}); // dst, cost
        }

        queue<array<int, 3>> q; 
        q.push({0, src, 0}); // stops, src, cost

        vector<int> dist(n, 1e9); 
        dist[src] = 0;

        while(!q.empty()) 
        { 
            auto [stops, node, cost] = q.front(); q.pop();

            // early stop
            if (stops>k) continue;
            
            for(auto it: adj[node])
            {
                if(cost+it.second < dist[it.first])
                {
                    dist[it.first] = cost+it.second; 
                    q.push({stops+1, it.first, dist[it.first]});
                }
            }
        }
        return (dist[dst]!=1e9)?dist[dst]:-1;
    }
};
