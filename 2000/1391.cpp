// 1391. Check if There is a Valid Path in a Grid
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if (m==1 && n==1) return true;

        const int *s = START[grid[0][0] - 1];
        return solve(grid, s[0]) || solve(grid, s[1]);
    }

private:
    int m, n;
    const int N = 0, E = 1, S = 2, W = 3;
    const int START[6][2] = {
        {E, W}, {N, S},
        {W, S}, {E, S},
        {N, W}, {N, E}
    };
    const int DIR[4][2] = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };
    const int NEXT[6][4] = {
        {-1,  E, -1,  W},
        { N, -1,  S, -1},
        { W,  S, -1, -1},
        { E, -1, -1,  S},
        {-1,  N,  W, -1},
        {-1, -1,  E,  N},
    };


    bool solve(vector<vector<int>>& grid, int dir) {
        if (dir==-1) return false;
        int y = DIR[dir][0], x = DIR[dir][1];
        bitset<301*301> visit;

        while (y>=0 && y<m && x>=0 && x<n) {
            int curr = y*n + x;
            if (visit[curr]) return false;
            visit[curr] = 1;

            dir = NEXT[grid[y][x]-1][dir];
            if (dir==-1) return false;
            if (y==m-1 && x==n-1) return true;
            
            y += DIR[dir][0];
            x += DIR[dir][1];
        }

        return false;
    }
};
