// 52. N-Queens II
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        return solve(board, 0, n);
    }

private:
    int solve(vector<vector<bool>>& board, int i, int n) {
        if (i==n) return 1;

        int result = 0;
        for (int j=0; j<n; j++) {
            if (check(board, i, j, n)) {
                board[i][j] = true;
                result += solve(board, i+1, n);
                board[i][j] = false;
            }
        }
        return result;
    }

    bool check(vector<vector<bool>>& board, int i, int j, int n) {
        for (int k=1; k<=i; k++) {
            if (j-k>=0 && board[i-k][j-k]) return false;
            if (j+k<n && board[i-k][j+k]) return false;
            if (board[i-k][j]) return false;
        }
        return true;
    }
};
