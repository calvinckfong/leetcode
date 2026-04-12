// 1320. Minimum Distance to Type a Word Using Two Fingers
class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<int>> dp(n, vector<int>(26, INT_MAX/2));
        fill(dp[0].begin(), dp[0].end(), 0);

        for (int i=1; i<n; i++) {
            int curr = word[i] - 'A';
            int prev = word[i-1] - 'A';
            int dist = getDist(prev, curr);
            for (int j=0; j<26; j++) {
                dp[i][j] = min(dp[i][j], dp[i-1][j]+dist);
                if (prev == j) {
                    for (int k=0; k<26; k++) {
                        int dist0 = getDist(k, curr);
                        dp[i][j] = min(dp[i][j], dp[i-1][k]+dist0);
                    }
                }
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }

private:
    int getDist(int p, int q) {
        int x1 = p/6, y1 = p%6;
        int x2 = q/6, y2 = q%6;
        return abs(x1-x2) + abs(y1-y2);
    }
};
