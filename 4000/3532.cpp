// 3532. Path Existence Queries in a Graph I
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int cnt = 0;
        vector<int> g(n, 0);
        for (int i=1; i<n; i++) {
            if (nums[i] - nums[i-1] > maxDiff) {
                cnt++;
            }
            g[i] = cnt;
        }

        int m = queries.size();
        vector<bool> res(m);
        for (int i=0; i<m; i++) {
            auto& q = queries[i]; 
            res[i] = g[q[0]] == g[q[1]];
        }
        return res;
    }
};
