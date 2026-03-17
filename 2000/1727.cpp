// 1727. Largest Submatrix With Rearrangements
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int, int>> prevH;

        int res = 0;
        for (int i=0; i<m; i++) {
            vector<pair<int, int>> heights;
            vector<bool> seen(n, false);

            for (auto [h, c]: prevH) {
                if (matrix[i][c] == 1) {
                    heights.push_back({h+1, c});
                    seen[c] = true;
                }
            }

            for (int j=0; j<n; j++) {
                if (!seen[j] && matrix[i][j]==1) {
                    heights.push_back({1, j});
                }
            }

            for (int j=0; j<heights.size(); j++) {
                res = max(res, heights[j].first * (j+1));
            }

            prevH = heights;
        }
        return res;
    }
};
