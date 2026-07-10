// 3534. Path Existence Queries in a Graph II
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> idx(n), pos(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return nums[a] < nums[b];
        });
        for (int i=0; i<n; i++) {
            pos[idx[i]] = i;
        }

        int m = 32 - __builtin_clz(n);
        vector<vector<int>> f(n, vector<int>(m));
        for ( int i=0, l=0; i<n; i++) {
            while (nums[idx[i]] - nums[idx[l]] > maxDiff) l++;
            f[i][0] = l;
        }

        for (int i=1; i<m; i++) {
            for (int j=0; j<n; j++) {
                f[j][i] = f[f[j][i-1]][i-1];
            }
        }

        vector<int> res;
        for (auto& q: queries) {
            int x = pos[q[0]], y = pos[q[1]];
            if (x>y) swap(x, y);
            if (x==y) {
                res.push_back(0);
                continue;
            }

            int s = 0;
            for (int i=m-1; i>=0; i--) {
                if (f[y][i] > x) {
                    y = f[y][i];
                    s += 1<<i;
                }
            }
            res.push_back(f[y][0]<=x ? s+1 : -1);
        }
        return res;
    }
};
