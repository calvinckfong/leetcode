// 3568. Minimum Moves to Clean the Classroom
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        const int dir[5] = {-1, 0, 1, 0, -1};
        int m = classroom.size(), n = classroom[0].size();
        vector<vector<int>> id(m, vector<int>(n));
        int sx, sy, cnt = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (classroom[i][j]=='S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j]=='L') {
                    id[i][j] = 1 << cnt++;
                }
            }
        }

        vector<vector<vector<int>>> bestE(m, vector<vector<int>>(n, vector<int>(1<<cnt, -1)));
        bestE[sx][sy][0] = energy;

        struct Info {
            int x, y, mask, e, steps;
        };
        queue<Info> q;
        const int done = (1<<cnt) - 1;
        q.push({sx, sy, 0, energy, 0});
        while (!q.empty()) {
            Info info = q.front();
            q.pop();
            if (info.mask == done) return info.steps;
            if (info.e == 0) continue;
            for (int d=0; d<4; d++) {
                int nx = info.x + dir[d];
                int ny = info.y + dir[d+1];
                if (nx<0 || nx>=m || ny<0 || ny>=n || classroom[nx][ny]=='X') {
                    continue;
                } 
                int ne = classroom[nx][ny] == 'R' ? energy : info.e-1;
                int nm = info.mask | id[nx][ny];
                if (ne > bestE[nx][ny][nm]) {
                    bestE[nx][ny][nm] = ne;
                    q.push({nx, ny, nm, ne, info.steps+1});
                }
            }
        }
        return -1;

    }
};
