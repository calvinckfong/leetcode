// 2911. Minimum Changes to Make K Semi-palindromes
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        factors = vector<vector<int>>(n+1);
        for (int i=1; i<=n/2; i++) {
            for (int j=i*2; j<=n; j+=i) {
                factors[j].push_back(i);
            }
        }

        vector cost(n, vector<int>(n, 0));
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                cost[i][j] = segmentCost(s, i, j-i+1);
            }
        }

        vector<int> prev(n);
        for (int i=0; i<n; i++) {
            prev[i] = cost[i][n-1];
        }

        for (int i=2; i<=k; i++) {
            vector<int> cur(n, n);
            int lim = n - 1 - 2*(i-1);
            for (int j=0; j<=n-2*i; j++) {
                for (int k=j+1; k<=lim; k++) {
                    cur[j] = min(cur[j], cost[j][k] + prev[k+1]);
                }
            }
            prev.swap(cur);
        }

        return prev[0];
    }

private:
    vector<vector<int>> factors;
    int segmentCost(const string& s, int l, int r) {
        int best = r;
        for (int x: factors[r]) {
            int grp = r / x, chg = 0;
            for (int offset=0; offset<x; offset++) {
                for (int i=0; i<grp/2; i++) {
                    if (s[l+offset+i*x] != s[l+offset+(grp-i-1)*x]) chg++;
                }
            }
            best = min(best, chg);
        }
        return best;
    }
};
