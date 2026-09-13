// 835. Image Overlap
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> p1, p2;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (img1[i][j]) p1.emplace_back(i, j);
                if (img2[i][j]) p2.emplace_back(i, j);
            }
        }

        vector<vector<int>> cnt(2*n, vector<int>(2*n));
        int res = 0;
        for (auto& i: p1) {
            for (auto& j: p2) {
                int dx = i.first - j.first + n;
                int dy = i.second - j.second + n;
                res = max(res, ++cnt[dx][dy]);
            }
        }
        return res;
    }
};
