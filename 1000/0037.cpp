// 37. Sudoku Solver
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c, char k)
    {
        for (int i=0; i<9; i++)
        {
            if (board[r][i] == k) return false;
            if (board[i][c] == k) return false;
        }

        for (int i=(r/3)*3; i<(r/3)*3+3; i++)
            for (int j=(c/3)*3; j<(c/3)*3+3; j++)
            {
                if (board[i][j] == k) return false;
            }

        return true;
    }

    bool solve(vector<vector<char>>& board, int r, int c)
    {
        if (r>=9) 
            return true;
        else if (c>=9)
            return solve(board, r+1, 0);
        else if (board[r][c]!='.') 
            return solve(board, r, c+1);
        else {
            for (char k='1'; k<='9'; k++)
            {
                if (isValid(board, r, c, k))
                {
                    //printf("set [%d][%d] to %c\n", r, c, k);
                    board[r][c] = k;
                    if (solve(board, r, c+1)) {return true;}
                    board[r][c] = '.';
                }
            }
            return false;
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
