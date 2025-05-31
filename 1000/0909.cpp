// 909. Snakes and Ladders
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> cols(n);
        iota(cols.begin(), cols.end(), 0);

        int i=1;
        vector<pair<int, int>> cells(n*n+1);
        for (int r=n-1; r>=0; r--) {
            for (int c: cols) {
                cells[i++] = {r, c};
            }
            reverse(cols.begin(), cols.end());
        }

        vector<int> dist(n*n+1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr+1; next<=min(curr+6, n*n); next++) {
                auto [r, c] = cells[next];
                int dest = (board[r][c]!=-1) ? board[r][c] : next;
                if (dist[dest]==-1) {
                    dist[dest] = dist[curr]+1;
                    q.push(dest);
                }
            }
        }
        return dist[n*n];
    }
};
