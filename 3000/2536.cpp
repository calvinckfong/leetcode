// 2536. Increment Submatrices by One
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n+1, vector<int>(n, 0));

        for (auto& q: queries) {
            res[q[0]][q[1]]++;
            res[q[2]+1][q[1]]--;
            if (q[3]<n-1)
            {
                res[q[0]][q[3]+1]--;
                res[q[2]+1][q[3]+1]++;
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=1; j<n; j++)
                res[i][j] += res[i][j-1];
        }

        for (int j=0; j<n; j++) {
            for (int i=1; i<n; i++)
                res[i][j] += res[i-1][j];
        }

        res.resize(n);
        return res;
    }
};
