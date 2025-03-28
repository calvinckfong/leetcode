// 2503. Maximum Number of Points From Grid Queries
class Solution {
public:
    const int dirs[5] = {1, 0, -1, 0, 1};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int qn = queries.size();
        int m = grid.size(), n = grid[0].size();
        int mn = m*n;

        vector<int> thres(mn + 1);
        vector<vector<int>> minVal(m, vector<int>(n, INT_MAX));
        minVal[0][0] = grid[0][0];

        priority_queue<array<int, 3>, vector<array<int,3>>, greater<array<int,3>>> pq;
        pq.push({grid[0][0], 0, 0});
        int visited = 0;
        while (!pq.empty()) {
            array<int,3> curr = pq.top();
            pq.pop();

            printf("visited %d, mn %d %d %d\n", visited, mn, curr[1], curr[2]);
            thres[++visited] = curr[0];

            for (int i=0; i<4; i++) {
                int nextm = curr[1] + dirs[i];
                int nextn = curr[2] + dirs[i+1];

                if (nextm >= 0 && nextm < m && 
                    nextn >= 0 && nextn < n &&
                    minVal[nextm][nextn] == INT_MAX) {
                    
                    minVal[nextm][nextn] = max(curr[0], grid[nextm][nextn]);

                    pq.push({minVal[nextm][nextn], nextm, nextn});
                }
            }
        }

        vector<int> result(qn);
        for (int i=0; i<qn; i++) {
            int threshold = queries[i];
            int l=0, r=mn;

            while (l<r) {
                int mid = l + (r-l+1)/2;
                if (thres[mid] < threshold) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            result[i] = l;
        }
        return result;
    }    
};
