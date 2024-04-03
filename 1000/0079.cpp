// 79. Word Search
class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;

    bool searchWord(int i, int j, int k, vector<vector<char>>& board, string word) {
        
        // end of word 
        if (k>=word.size()) return true;
        int offset[5] = {-1, 0, 1, 0, -1};
        char c = word[k];

        for (int o=0; o<4; o++) {
            int ii = i + offset[o];
            int jj = j + offset[o+1];
            if (ii<0 || jj<0 || ii>=m || jj>=n) continue;
            if (visited[ii][jj]) continue;
            if (board[ii][jj] == c) {
                visited[ii][jj] = true;
                if ( !searchWord(ii, jj, k+1, board, word) )
                    visited[ii][jj] = false;
                else
                    return true;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] != word[0]) continue;
                
                visited = vector<vector<bool>>(m, vector<bool>(n, false));
                visited[i][j] = true;
                if ( searchWord(i, j, 1, board, word) )
                    return true;
            }
        }
        return false;
    }
};
