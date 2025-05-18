// 1931. Painting a Grid With Three Different Colors
class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1e9 + 7;
        unordered_map<int, vector<int>> valid;

        int mask_end = pow(3, m);
        for (int i=0; i<mask_end; i++) {
            vector<int> color;
            int mn = i;
            for (int j=0; j<m; j++) {
                color.push_back(mn%3);
                mn /= 3;
            }
            bool check = true;
            for (int j=0; j<m-1; j++) {
                if (color[j] == color[j+1]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                valid[i] = std::move(color);
            }
        }

        unordered_map<int, vector<int>> adjacent;
        for (const auto& [mask1, color1]: valid) {
            for (const auto& [mask2, color2]: valid) {
                bool check = true;
                for (int i=0; i<m; i++) {
                    if (color1[i] == color2[i]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    adjacent[mask1].push_back(mask2);
                }
            }
        }
        vector<int> f(mask_end);
        for (auto& [mask, _]: valid) {
            f[mask] = 1;
        }
        for (int i=1; i<n; i++) {
            vector<int> g(mask_end);
            for (auto& [mask2, _]: valid) {
                for (int& mask1: adjacent[mask2]) {
                    g[mask2] = (g[mask2] + f[mask1]) % MOD;
                }
            }
            f = std::move(g);
        }
        int ans = 0;
        for (int num: f) {
            ans = (ans + num) % MOD;
        }
        return ans;
    }
};
