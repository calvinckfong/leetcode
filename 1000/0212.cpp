// 212. Word Search II
struct TrieNode {
    bool isEnd = false;
    bool picked = false;
    TrieNode* children[26] ={0};
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w: words) {
            TrieNode* node = root;
            for (char c: w) {
                int idx = c-'a';
                if (!node->children[idx])
                    node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->isEnd = true;
        }

        result.clear();
        m = board.size();
        n = board[0].size();

        // vector<vector<int>> visited(m, vector<int>(n, false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                TrieNode* node = root;
                char c = board[i][j];
                if (node->children[c-'a']) {
                    board[i][j] = '.';
                    string str(1, c);
                    searchWord(i, j, board, str, node->children[c-'a']);
                    board[i][j] = c;
                }
            }
        }

        return result;
    }

private:
    const int delta[5] = {0, 1, 0, -1, 0};
    int m, n;
    vector<string> result;

    void searchWord(int i, int j, vector<vector<char>>& board, string str, TrieNode* node) {
        if (node->isEnd && !node->picked) {
            result.push_back(str);
            node->picked = true;
        }
        
        for (int k=0; k<4; k++) {
            int ii = i + delta[k];
            int jj = j + delta[k+1];
            if (ii<0 || ii>= m || jj<0 || jj>=n) continue;
            char c = board[ii][jj];
            if (c == '.') continue;
            
            TrieNode* next = node->children[c-'a'];
            if (next)
            {
                board[ii][jj] = '.';
                searchWord(ii, jj, board, str + c, next);
                board[ii][jj] = c;
            }
        }
    }
};
