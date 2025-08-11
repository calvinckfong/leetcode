// 2438. Range Product Queries of Powers
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> bins;
        int rep = 1;
        while (n) {
            if (n&1) bins.push_back(rep);
            n /= 2;
            rep *= 2;
        }

        int m = bins.size();
        long long curr;
        int comb[30][30];
        for (int i=0; i<m; i++) {
            curr = 1LL;
            for (int j=i; j<m; j++) {
                curr = curr * bins[j] % MOD;
                comb[i][j] = curr;
            }
        }

        int i=0;
        vector<int> res(queries.size());
        for (auto& q: queries) {
            res[i++] = comb[q[0]][q[1]];
        }
        return res;
    }
};
