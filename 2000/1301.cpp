// 1301. Number of Paths with Max Score
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        dp = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n, {-1, 0}));
        dp[n-1][n-1] = {0, 1};
        for (int i=n-1; i>=0; --i) {
            for (int j=n-1; j>=0; --j) {
                if (!(i==n-1 && j==n-1) && board[i][j] != 'X') {
                    update(i, j, i+1, j);
                    update(i, j, i,   j+1);
                    update(i, j, i+1, j+1);
                    if (dp[i][j].first != -1) {
                        dp[i][j].first +=
                            (board[i][j] == 'E' ? 0 : board[i][j] - '0');
                    }
                }
            }
        }
        return dp[0][0].first == -1 ? vector<int>{0, 0}
                   : vector<int>{dp[0][0].first, dp[0][0].second};
    }

private:
    int n;
    vector<vector<pair<int, int>>> dp;
    void update(int x, int y, int u, int v) {
        const int MOD = 1e9 + 7;
        if (u >= n || v >= n || dp[u][v].first == -1) {
            return;
        }
        if (dp[u][v].first > dp[x][y].first) {
            dp[x][y] = dp[u][v];
        } else if (dp[u][v].first == dp[x][y].first) {
            dp[x][y].second += dp[u][v].second;
            if (dp[x][y].second >= MOD) {
                dp[x][y].second -= MOD;
            }
        }
    }
    


};
