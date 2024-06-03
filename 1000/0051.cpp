// 51. N-Queens
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(result, board, 0, n);
        return result;
    }

private:
    void solve(vector<vector<string>>& result, vector<string>& board, int i, int n) {
        if (i==n) {
            result.push_back(board);
            return;
        }

        for (int j=0; j<n; j++) {
            if (check(board, i, j, n)) {
                board[i][j] = 'Q';
                solve(result, board, i+1, n);
                board[i][j] = '.';
            }
        }
    }

    bool check(vector<string>& board, int i, int j, int n) {
        for (int k=1; k<=i; k++) {
            if (j-k>=0 && board[i-k][j-k]=='Q') return false;
            if (j+k<n && board[i-k][j+k]=='Q') return false;
            if (board[i-k][j]=='Q') return false;
        }
        return true;        
    }
};
