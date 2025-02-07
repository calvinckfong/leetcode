// 3160. Find the Number of Distinct Colors Among the Balls
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colors, balls;

        for (int i=0; i<n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];

            if (balls.find(ball) != balls.end()) {
                int prevColor = balls[ball];
                colors[prevColor]--;

                if (colors[prevColor]==0) colors.erase(prevColor);
            }
            balls[ball] = color;
            colors[color]++;
            result[i] = colors.size();
        }
        return result;
    }
};
