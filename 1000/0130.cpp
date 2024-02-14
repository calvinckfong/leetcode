// 130. Surrounded Regions
class Solution {
public:
    int m, n;
    queue<vector<int>> edgeCell;
    void grow(vector<vector<char>>& board, int i, int j)
    {
        board[i][j] = 'X'; // border cell
        edgeCell.push({i, j});
        if (i>0   && board[i-1][j] == 'O') grow(board, i-1, j);
        if (i<m-1 && board[i+1][j] == 'O') grow(board, i+1, j);
        if (j>0   && board[i][j-1] == 'O') grow(board, i, j-1);
        if (j<n-1 && board[i][j+1] == 'O') grow(board, i, j+1);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        // mark border cells
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (i==0 || i==m-1 || j==0 || j==n-1)
                    if (board[i][j]=='O')
                        grow(board, i, j);

        // flip all cells
        board = vector<vector<char>>(m, vector<char>(n, 'X'));

        // restore border cells
        while (!edgeCell.empty())
        {
            auto pos = edgeCell.front();
            board[pos[0]][pos[1]] = 'O';
            edgeCell.pop();
        }
    }
};
