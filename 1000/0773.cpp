// 773. Sliding Puzzle
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const vector<int> nextCell[6] = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };
        const string target = "123450";

        int m = board.size(), n = board[0].size();
        string state;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                state += to_string(board[i][j]);
        
        unordered_set<string> visited;
        queue<string> q;
        q.push(state);
        visited.insert(state);

        // bfs
        int result = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size-->0) {
                string currState = q.front();
                q.pop();

                if (currState==target) return result;

                int zPos = currState.find('0');
                for (int p: nextCell[zPos]) {
                    string nextState = currState;
                    swap(nextState[zPos], nextState[p]);
                    if (!visited.count(nextState)) {
                        visited.insert(nextState);
                        q.push(nextState);
                    }
                }
            }
            result++;
        }
        return -1;
    }
};
