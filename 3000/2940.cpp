// 2940. Find Building Where Alice and Bob Can Meet
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int nq = queries.size();
        int nh = heights.size();
        
        vector<vector<vector<int>>> visited(nh);
        vector<int> result(nq, -1);

        for (int i=0; i<nq; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a>b) swap(a, b);

            if (a==b) result[i] = a;
            else if (heights[b]>heights[a]) result[i] = b;
            else visited[b].push_back({heights[a], i});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i=0; i<nh; i++) {
            while (!pq.empty() && pq.top()[0] < heights[i]) {
                result[pq.top()[1]] = i;
                pq.pop();
            }

            for (auto& v: visited[i])
                pq.push(v);
        }

        return result;
    }
};
