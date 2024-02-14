// 36. Valid Sudoku
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        for (int i=0; i<9; i++)
        {
            map<char, int> freq;
            for (int j=0; j<9; j++)
            {
                char c = board[i][j];
                if (c=='.') continue;
                freq[c]++;
                if (freq[c]>1) return false;
            }
        }

        // col
        for (int i=0; i<9; i++)
        {
            map<char, int> freq;
            for (int j=0; j<9; j++)
            {
                char c = board[j][i];
                if (c=='.') continue;
                freq[c]++;
                if (freq[c]>1) return false;
            }
        }

        // block
        for (int i=0; i<9; i++)
        {
            int blk_col = i%3;
            int blk_row = i/3;
            map<char, int> freq;
            for (int j=0; j<9; j++)
            {
                int x = blk_col*3 + (j%3);
                int y = blk_row*3 + (j/3);
                char c = board[y][x];
                if (c=='.') continue;
                freq[c]++;
                if (freq[c]>1) {
                    return false;
                }
            }
        }

        return true;
    }
};
